#include "Core.h"
#include "grade.h"
#include <sstream>

using namespace std;

Core::Core(istream& is)
{
    read(is);
}

double Core::grade() const
{
    return ::grade(midterm, final, homework);
}

istream& Core::read_common(istream& in)
{
    in >> n >> midterm >> final;
    return in;
}

istream& Core::read(istream& in)
{
    read_common(in);
    read_hw(in, homework);
    return in;
}

bool compare(const Core& x, const Core& y)
{
    return x.name() < y.name();
}

bool compare_grade(const Core& x, const Core& y)
{
    return x.grade() < y.grade();
}

bool compare_grade_ptr(const Core* x, const Core* y)
{
    return x->grade() < y->grade();
}

istream& read_hw(istream& in, Vec<double>& hw)
{
    hw.clear();

    string line;
    getline(in, line);
    istringstream record(line);

    double x;
    while (record >> x) {
        hw.push_back(x);
    }

    return in;
}

