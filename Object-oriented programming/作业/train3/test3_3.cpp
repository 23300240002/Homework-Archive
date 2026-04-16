#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <string>
using namespace std;

struct Student {
    std::string name;
    int score;
};

void task1() {
    vector<int> numbers = {3, 5, 2, 8, 1, 10};

    vector<int> doubled;
    // 使用第3课所学的back_inserter来插到末尾
    transform(numbers.begin(), numbers.end(), back_inserter(doubled),
        [](int x) { return x * 2; }); // lambda表达式

    vector<int> filtered;
    copy_if(numbers.begin(), numbers.end(), back_inserter(filtered),
        [](int x) { return x > 5; });

    vector<int> sorted_numbers = numbers;
    sort(sorted_numbers.begin(), sorted_numbers.end(),
        [](int a, int b) { return abs(a - 5) < abs(b - 5); });

    cout << "Doubled vector: ";
    for (auto it = doubled.begin(); it != doubled.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Filtered vector (> 5): ";
    for (auto it = filtered.begin(); it != filtered.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Sorted by absolute difference from 5: ";
    for (auto it = sorted_numbers.begin(); it != sorted_numbers.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void task2() {
    vector<Student> students = {{"Alice", 85}, {"Bob", 72}, {"Charlie", 90}};

    sort(students.begin(), students.end(),
        [](const Student& a, const Student& b) { return a.score > b.score; });

    cout << "Students sorted by score (descending):" << endl;
    for (auto it = students.begin(); it != students.end(); ++it) {
        cout << it->name << ": " << it->score << endl;
    }

    cout << endl;
    cout << "Students with score > 80:" << endl;
    for_each(students.begin(), students.end(),
        [](const Student& s) {
            if (s.score > 80) cout << s.name << endl;
        });
}

void task3() {
    vector<int> numbers = {3, 5, 2, 8, 1, 10};

    // accumulate 原本为求和，可指定第四个参数为具体函数来实现其他功能
    int product = accumulate(numbers.begin(), numbers.end(), 1, // 第三个参数为初始值
        [](int acc, int x) { // 这里 acc 是累积器，x 是当前考察的元素。操作较为炫酷，超出认知
            if (x % 2 == 0) {
                return acc * x;
            }
            return acc;
        });

    cout << "Product of even numbers: " << product << endl;
}

int main() {
    cout << "Task 1 Solution:" << std::endl;
    task1();

    cout << "\nTask 2 Solution:" << std::endl;
    task2();

    cout << "\nTask 3 Solution:" << std::endl;
    task3();

    return 0;
}