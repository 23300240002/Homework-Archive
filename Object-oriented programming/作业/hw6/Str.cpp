#include "Str.h"

Str& Str::operator+=(const Str& s)
{
	std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
	return *this;
}

std::istream& operator>>(std::istream& is, Str& s)
{
	s.data.clear();

	char c;
	while (is.get(c) && std::isspace(c))
		;

	if (is) {
		do {
			s.data.push_back(c);
		} while (is.get(c) && !std::isspace(c));

		if (is) {
			is.unget();
		}
	}

	return is;
}

std::ostream& operator<<(std::ostream& os, const Str& s)
{
	for (Str::size_type i = 0; i != s.size(); ++i) {
		os << s[i];
	}
	return os;
}

Str operator+(const Str& s, const Str& t)
{
	Str r = s;
	r += t;
	return r;
}
