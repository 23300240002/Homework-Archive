#ifndef _STRING_H
#define _STRING_H

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <cstring>
#include "Vec.h"

class Str{
	friend std::istream& operator>>(std::istream&, Str&);

public:
	typedef Vec<char>::size_type size_type;

	Str() { }
	Str(size_type n, char c) : data(n, c) { }
	Str(const char* cp) {
		std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));
	}

	template <class In>
	Str(In b, In e) {
		std::copy(b, e, std::back_inserter(data));
	}

	size_type size() const { return data.size(); }

	char& operator[](size_type i) { return data[i]; }
	const char& operator[](size_type i) const { return data[i]; }

	Str& operator+=(const Str&);

private:
	Vec<char> data;
};

std::istream& operator>>(std::istream&, Str&);
std::ostream& operator<<(std::ostream&, const Str&);
Str operator+(const Str&, const Str&);


#endif
