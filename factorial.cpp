#include <iostream>

using namespace std;


int factorial(int n)
{

  if (n == 1)
    return 1;

  return factorial(n-1) * n;

}

float factorial(float n)
{

  if (n == 1)
    return 1;

  return factorial(n-1) * n;

}

long factorial(long n)
{

  if (n == 1)
    return 1;

  return factorial(n-1) * n;

}


long long factorial(long long n)
{

  if (n == 1)
    return 1;

  return factorial(n-1) * n;

}


long double factorial(long double n)
{

  if (n == 1)
    return 1;

  return factorial(n-1) * n;

}


int main()
{

  int num_i = 20;
  float num_f = 20;
  long num_l = 20;
  long long num_ll = 20;
  long double num_ld = 20;

  
  //int fact = factorial(20);

  printf("%d \n %f \n %ld \n %lld \n %Lf \n\n", factorial(num_i), factorial(num_f), factorial(num_l), factorial(num_ll), factorial(num_ld));


}
