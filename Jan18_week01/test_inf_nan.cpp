#include <iostream>
#include <cmath>

using namespace std;


static void isPosInf(double num)
{

  if(signbit(num) == 0 && isinf(num) == 1)
    cout << num << " is positive infinity" << endl;
  else
    cout << num << " is not positive infinity" << endl;

}

static void isNegInf(double num)
{

  if(signbit(num) == 1 && isinf(num) == 1)
    cout << num << " is negative infinity" << endl;
  else
    cout << num << " is not negative infinity" << endl;

}


static void isNan(double num)
{

  if(isnan(num) == 1)
    cout << num << " is NAN" << endl;
  else
    cout << num << " is not NAN" << endl;

}


int main()
{

  double x, y, r1, r2;

  x = 0.0;
  y = -0.0;

  r1 = 1/x;   //pos inf
  r2 = 1/y;   //neg inf

  double s1 = 1/r1;
  double s2 = 1/r2;

  isPosInf(x);
  isPosInf(y);
  isPosInf(r1);
  isPosInf(r2);

  cout << endl;

  isNegInf(x);
  isNegInf(y);
  isNegInf(r1);
  isNegInf(r2);

  cout << endl;

  int a=4;

  isNan(-a);
  isNan(y);
  isNan(r1);
  isNan(r2+r1);

  cout << endl;
  //printf("%f %f\n\n", r1, r2);
  //cout << "r1 = " << r1 << " r2 = " << r2 << " s1 = " << s1 << " s2 = " << s2 << endl << endl;

}
