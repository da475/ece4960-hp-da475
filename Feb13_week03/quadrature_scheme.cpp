#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double exp_val = exp(1) - exp(-1);
    cout << "exp is " << exp_val << endl;

    double exact_val = 2.3504;
    double rect = 0.0;
    double mid = 0.0;
    double trap = 0.0;
    double simpson = 0.0;
    double gauss_2pt = 0.0;
    float h=0.1;
    for (float i=-1.0; i<1.0; i+=h) {
        rect += h * exp(i);
        mid += h * exp(i + (h/2));
        trap += h * (0.5*exp(i) + 0.5*exp(i+h));
        simpson += h * ( ((1.0/6.0) * exp(i)) + ((4.0/6.0) * exp(i+(h/2))) + ((1.0/6.0) * exp(i+h)) );
        gauss_2pt += h * 0.5 * ( (exp(i + h/2 - (0.5 * (1/sqrt(3)) * h))) + (exp(i + h/2 + (0.5 * (1/sqrt(3)) * h))) );
    }

    cout << "rectangle is " << exact_val-rect << endl;
    cout << "trapezoid is " << exact_val-trap << endl;
    cout << "mid-point is " << exact_val-mid << endl;
    cout << "simpson is " << exact_val-simpson << endl;
    cout << "gauss_2pt is " << exact_val-gauss_2pt << endl;

    return 0;
}


