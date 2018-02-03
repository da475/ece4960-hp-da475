#include <iostream>
#include <cmath>

int main()
{

  double a, b, c;
  double x1, x2;

  a = pow(10, -5);
  b = pow(10, 3);
  c = pow(10, 3);

  x1 = ((-b) + sqrt(b*b - 4*a*c)) / (2*a);
 // x1 = sqrt(b*b - 4*a*c);
  
  //x2 = 4;

  x2 = (2*c) / (-b + sqrt(b*b - 4*a*c));

  printf("%f %f\n\n", x1, x2);
  

}
