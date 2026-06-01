#ifndef GUARD_Student_info
#define GUARD_Student_info

#include "Vec.h"
#include <string>
#include <istream>
#include <iostream>
#include "Core.h"
#include "Grad.h"

class Student_info{
public:
    Student_info() : cp(0) {}
    Student_info(std::istream& is) : cp(0) { read(is); }
    Student_info(const Student_info&);
    Student_info& operator=(const Student_info&);
    ~Student_info() { delete cp; }

    std::istream& read(std::istream&);
    std::string name() const;
    double grade() const;

    static bool compare_grade(const Student_info&, const Student_info&);

private:
    Core* cp;
};


#endif
