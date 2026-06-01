#include "Grad.h"
#include "grade.h"

using namespace std;

Grad::Grad(istream& is)
{
    read(is);
}

double Grad::grade() const
{
    double core_grade = Core::grade();
    return core_grade < thesis ? core_grade : thesis;
}

istream& Grad::read(istream& in)
{
    read_common(in);
    in >> thesis;
    read_hw(in, homework);
    return in;
}
