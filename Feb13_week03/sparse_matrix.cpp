#include <iostream>
#include <cmath>

using namespace std;

class sparse_matrix {
    private:
    int value[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int rowptr[6] = {0,3,6,9,10,12};
    int colind[12] = {0,1,4,0,1,2,1,2,4,3,0,4};

    public:
    int retrieve_element(int r, int c) {
        int rowval = rowptr[r];
        int elements_in_row = rowptr[r+1] - rowptr[r];
    
        if(!elements_in_row) return 0;

        // find the column index, corresponding index in val array is the element
        // if not found, then it is a zero value
        for(int i=rowptr[r]; i<rowptr[r+1]; i++) {
            if(colind[i] == c)
                return value[i];
        }
        return 0;
    }

    // refb is the reference product calculated from full-matrix rep
    // function returns 1 is mis-match is found with compressed form
    // function returns 0 is no mis-match is found
    int productAx(int X[], int refb[]) {
        int testb[5] = {0};
        
        // calculate B using compressed form
        for (int i=0; i<5; i++) {
            for(int j=0; j<5; j++) {
                testb[i] += retrieve_element(i,j) * X[j];
            }
        }

        // test with full-matrix representation
        for (int i=0; i<5; i++) {
            if (refb[i] != testb[i]) return 1;
        }
        return 0;
    }
};

int main()
{
    int mat[5][5] = { {1,2,0,0,3}, {4,5,6,0,0}, {0,7,8,0,9}, {0,0,0,10,0}, {11,0,0,0,12}};
    int value[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int rowptr[6] = {0,3,6,9,10,12};
    int colind[12] = {0,1,4,0,1,2,1,2,4,3,0,4};
    int X[5] = {5,4,3,2,1};
    int B[5] = { 0 };

    sparse_matrix *sm = new sparse_matrix();

    // Call retrieveElement for each element and
    // print the matrix in 2-D form
    for (int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            B[i] += mat[i][j] * X[j];
            //cout << " " << sm->retrieve_element(i, j);
        }
        //cout << endl;
    }

    cout << "Result of productAx is "<< sm->productAx(X, B) << endl;
        
    return 0;
}


