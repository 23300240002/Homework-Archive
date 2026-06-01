#pragma warning(disable: 4786)
#include <iostream>
#include "Complex.h"
using namespace std;

int main()
{
  Complex c1,c2;
  cout <<"please input two complex numbers(for example: 1+2i):\n";
  cin >> c1;
  cin >> c2;
  cout << c1 + c2 << endl;
  cout << 2  + c2 <<endl;
  return 0;
}
