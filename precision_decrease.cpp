#include <iostream>
#include <cmath>

using namespace std;



int main()
{

  double x, y, r1, r2;

  x = 1.234567890123456;;
  int i = 1;

  x *= pow(10, -307);

  for (i=1; i<20; i++)
  {
  
    x /= 10.0;
    //printf("%f \n", x);
    cout.precision(15);
    cout << "val is " << x << endl;

  }

}
