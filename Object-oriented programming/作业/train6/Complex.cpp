#include <iostream>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <string>
#include "Complex.h"

using namespace std;

Complex& Complex::operator+=(const Complex& c) {
    real += c.real;
    image += c.image;
    return *this;
}

Complex operator+(const Complex& c1, const Complex& c2) {
    Complex sum = c1;
    sum += c2;
    return sum;
}

ostream& operator<<(ostream& os, const Complex& c) {
    if (c.image == 0.0) { // 如果虚部为零，只输出实部
        os << c.real;
    } else if (c.real == 0.0) { // 如果实部为零，只输出虚部（带 i）
        if (c.image == 1.0) os << "i"; // 1 省略不写
        else if (c.image == -1.0) os << "-i"; // -1 省略不写
        else os << c.image << "i";
    } else { // 否则，实部非零，虚部非零，正常输出
        os << c.real;
        if (c.image > 0) os << "+";
        if (c.image == 1.0) os << "i"; // 1 省略不写
        else if (c.image == -1.0) os << "-i"; // -1 省略不写
        else os << c.image << "i";
    }
    return os;
}

istream& operator>>(istream& is, Complex& c) {
    string s;
    is >> s;
    if (!is) {
        return is;
    }

    // 去掉开头的无效字符
    while (!s.empty()) {
        unsigned char ch = static_cast<unsigned char>(s[0]);
        if (std::isdigit(ch) || s[0] == '+' || s[0] == '-' || s[0] == '.' || s[0] == 'i') {
            break;
        }
        s.erase(0, 1);
    }

    // 搞一个辅助函数，一劳永逸
    // 将字符串转为 double
    auto toDouble = [](const string& str) -> double {
        if (str.empty()) return 0.0;
        if (str == "+") return 1.0;
        if (str == "-") return -1.0;
        stringstream ss(str);
        double val;
        ss >> val;
        return val;
    };

    size_t iPos = s.find('i'); // 找 i 的位置，判断是否为纯实数或纯虚数
    if (iPos == string::npos) { // 纯实数
        stringstream real_in(s);
        real_in >> c.real;
        c.image = 0.0;
        return is;
    }
    
    // 如果不是纯实数，那么需要用 i 的位置来切分
    string left = s.substr(0, iPos);    // i 左边部分
    string right = s.substr(iPos + 1);  // i 右边部分

    if (right.empty()) {
        // i 在末尾：可能是 a+bi、a-bi 或 纯虚数 bi 或 i/+i/-i
        size_t sep = string::npos;
        for (size_t k = 1; k < left.size(); ++k) {
            if (left[k] == '+' || left[k] == '-') {
                sep = k;
                break;
            }
        }
        if (sep != string::npos) { // a+bi 或 a-bi
            string realPart = left.substr(0, sep);
            string imagPart = left.substr(sep);
            c.real = toDouble(realPart);
            c.image = toDouble(imagPart);
        } else { // 纯虚数，需要额外处理 ±1 的情况
            if (left.empty() || left == "+") c.image = 1.0;
            else if (left == "-") c.image = -1.0;
            else c.image = toDouble(left);
            c.real = 0.0;
        }
    } else { // i 在中间（虚部在左，实部在右）
        c.real = toDouble(right);
        if (left.empty() || left == "+") c.image = 1.0;
        else if (left == "-") c.image = -1.0;
        else c.image = toDouble(left);
    }

    return is;
}