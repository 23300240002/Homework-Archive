#ifndef _COMPLEX_H
#define _COMPLEX_H

#include <iostream>

class Complex{
    // 输入和输出算作友元函数，是因为需要保持 os/is << c1 的顺序
    // 因为如果写成成员函数，那么只能是 c1 << os/is
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);
    // 加法运算符也算作友元函数，是因为要使得两边能够隐式类型转换
    // 否则 1 + c2 会报错，因为 1 还是 int 类型
    friend Complex operator+(const Complex& c1, const Complex& c2);

public:
    // 构造函数，直接初始化实部和虚部为0
    Complex(double r = 0, double i = 0) : real(r), image(i) {}
    // += 运算符重载，可以算作成员函数
    // 因为非常符合左侧原数、中间操作符、右边操作数的语法
    Complex& operator+=(const Complex& c);

private:
    double real; // 实部
    double image; // 虚部
};

// 由于是友元函数，所以需要在 Complex 类的外部定义
Complex operator+(const Complex& c1, const Complex& c2);
#endif
