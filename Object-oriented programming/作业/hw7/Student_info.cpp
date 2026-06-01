#include <istream>
#include <stdexcept>
#include "grade.h"
#include "Student_info.h"

using namespace std;

Student_info::Student_info(const Student_info& s) : cp(0)
{
    if (s.cp) {
        cp = s.cp->clone();
    }
}

Student_info& Student_info::operator=(const Student_info& s)
{
    if (&s != this) {
        delete cp;
        cp = s.cp ? s.cp->clone() : 0;
    }
    return *this;
}

istream& Student_info::read(istream& is)
{
    delete cp;
    cp = 0;

    char ch;
    if (!(is >> ch)) {
        return is;
    }

    if (ch == 'U') {
        cp = new Core(is);
    } else {
        cp = new Grad(is);
    }

    return is;
}

string Student_info::name() const
{
    if (cp) {
        return cp->name();
    }
    throw runtime_error("uninitialized Student");
}

double Student_info::grade() const
{
    if (cp) {
        return cp->grade();
    }
    throw runtime_error("uninitialized Student");
}

bool Student_info::compare_grade(const Student_info& x, const Student_info& y)
{
    return x.grade() < y.grade();
}


