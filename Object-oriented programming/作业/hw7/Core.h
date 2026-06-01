#ifndef GUARD_CORE
#define GUARD_CORE

#include <string>
#include <istream>
#include <iostream>
#include "Vec.h"


class Core{
    friend class Student_info;

public:
    Core() : midterm(0), final(0) {}
    Core(std::istream&);
    virtual ~Core() {}

    std::string name() const { return n; }
    virtual double grade() const;
    virtual std::istream& read(std::istream&);

protected:
    std::istream& read_common(std::istream&);
    virtual Core* clone() const { return new Core(*this); }

    double midterm, final;
    Vec<double> homework;

private:
    std::string n;

};

bool compare(const Core &x, const Core &y);
bool compare_grade(const Core &x, const Core &y);
bool compare_grade_ptr(const Core *x, const Core *y);
std::istream & read_hw(std::istream & in, Vec<double> & hw);

#endif
