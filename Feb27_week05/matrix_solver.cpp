#include <iostream>
#include <cmath>

using namespace std;

/*
Gaussian elimination needs 3 elements
- row perm
- col perm
- row scaling
*/

void mat_solver(double value) {

    double mat[2][2] = { {100,99}, {99, 98.01-exp(value)}};
    double det_mat = (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);
    double inv_mat[2][2];

    double c1 = 199;
    double c2 = 197;

    inv_mat[0][0] = mat[1][1];
    inv_mat[0][1] = -mat[0][1];
    inv_mat[1][0] = -mat[1][0];
    inv_mat[1][1] = mat[0][0];

    inv_mat[0][0] = det_mat * inv_mat[0][0];
    inv_mat[0][1] = det_mat * inv_mat[0][1];
    inv_mat[1][0] = det_mat * inv_mat[1][0];
    inv_mat[1][1] = det_mat * inv_mat[1][1];

    double x = (inv_mat[0][0] * c1) + (inv_mat[0][1] * c2);
    double y = (inv_mat[1][0] * c1) + (inv_mat[1][1] * c2);

    cout << "for e = "<< value << ", x = " << x << endl;
    cout << "y = " << y << endl;
    cout << endl;
}

int main()
{
    double e = 0.01;
    for(int i=0; i<10; i++) {
        mat_solver(e);
        e = e * 0.1;
    }
    return 0;
}


