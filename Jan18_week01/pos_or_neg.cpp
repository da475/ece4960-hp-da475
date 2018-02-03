#include <iostream>
#include <cmath>

using namespace std;


static int isPos(double num)
{

  double is_inf = 1/num;

  //double INF = 1/0;

  if(is_inf == inf)
    cout << "pos 0" << endl;
  else
    cout << "not pos 0" << endl;

}

int main()
{

  double x, y, r1, r2;

  x = 0.0;
  y = -0.0;

  r1 = 1/x;   //pos inf
  r2 = 1/y;   //pos inf

  double s1 = 1/r1;
  double s2 = 1/r2;

  isPos(s1);
  isPos(s2);

  //r2 = y/x;

  printf("%f %f\n\n", r1, r2);
  cout << "r1 = " << r1 << " r2 = " << r2 << " s1 = " << s1 << " s2 = " << s2 << endl << endl;

}
