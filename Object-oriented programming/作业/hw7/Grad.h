#ifndef GUARD_GRAD
#define GUARD_GRAD

#include <string>
#include <istream>
#include <iostream>
#include "Vec.h"
#include "Core.h"

class Grad: public Core{
public:
    Grad() : thesis(0) {}
    Grad(std::istream&);

    double grade() const;
    std::istream& read(std::istream&);

protected:
    Grad* clone() const { return new Grad(*this); }

private:
    double thesis;
};

#endif
