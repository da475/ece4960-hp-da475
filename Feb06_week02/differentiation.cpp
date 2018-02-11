#include <iostream>
#include <cmath>

using namespace std;


static double fx(double num)
{

  return (num * num);

}
static double fx_offset(double num)
{

  double offset = pow(10, 10);
  return (num * num) + offset;

}

int main()
{

  double h = 0.1;
  double x = 1;

  for (int i = 0; i < 50; i++)
  {
    double f_x = (fx(x+h) - fx(x)) / h;
    double f_x_off = (fx_offset(x+h) - fx_offset(x)) / h;

    double f_xx = (fx(x+h) - fx(x-h)) / 2*h;
    double f_xx_off = (fx_offset(x+h) - fx_offset(x-h)) / 2*h;
    cout << "f_x is " << f_x << " for h = " << h << endl;
    cout << "f_xx is " << f_xx << " for h = " << h << endl;
    cout << "f_x_off is " << f_x_off << " for h = " << h << endl;
    cout << "f_xx_off is " << f_xx_off << " for h = " << h << endl;
    h = h/10;
  }



  //printf("%f %f\n\n", r1, r2);
  //cout << "r1 = " << r1 << " r2 = " << r2 << " s1 = " << s1 << " s2 = " << s2 << endl << endl;

}
