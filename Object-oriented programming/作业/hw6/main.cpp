#pragma warning(disable: 4786)
#include <iostream>
#include "Vec.h"
#include "Str.h"
using namespace std;

int main()
{
  Str name;
  cout << "Please input your name:" << endl;
  cin >> name;
  const Str greeting = "Hello, " + name + "!";
  Str second(greeting.size(), ' ');
  second = "* " + second + " *";
  Str msg = "* " + greeting + " *";
  Str first(second.size(), '*');

  cout << first << endl;
  cout << second << endl;
  cout << msg << endl;
  cout << second << endl;
  cout << first << endl;

  return 0;
}
