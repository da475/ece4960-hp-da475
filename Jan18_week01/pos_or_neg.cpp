#include <iostream>
#include <cmath>

using namespace std;


static void isPos(double num)
{

  if(signbit(num) == 0)
    cout << "positive" << endl;
  else
    cout << "not positive" << endl;

}


static void isNeg(double num)
{

  if(signbit(num) == 1)
    cout << "negative" << endl;
  else
    cout << "not negative" << endl;

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

  isPos(y);
  //isPos(y);


  //printf("%f %f\n\n", r1, r2);
  //cout << "r1 = " << r1 << " r2 = " << r2 << " s1 = " << s1 << " s2 = " << s2 << endl << endl;

}
