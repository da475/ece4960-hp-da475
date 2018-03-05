#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>

// include the class header file
#include "MatrixOperations.h"

// Allows functions in the std namespace to be used without their prefix
// std::cout becomes cout
using namespace std;

// Function to print a matrix in full-compressed format
void MatrixOperations::printMatrixFull() {

    cout << "Matrix in full-format is" << endl << endl;
    for (int i = 0; i < rank; i++) {
        for (int j = 0; j < rank; j++) {
            cout << arr[i*rank + j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
    return;
}

// Function to print a matrix in row-compressed format
void MatrixOperations::printMatrixSparse() {

    cout << "Matrix in row-format is" << endl << endl;
    for (int i = 0; i <= rank; i++) {
        for (int j = rowPtr[i]; j < rowPtr[i+1]; j++) {
            cout << value[j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
    return;
}

// Function to convert a matrix to row-compressed format
void MatrixOperations::createMatrix() {
    cout << endl;
    if (nZ == -1) {
        nZ = 0;
        for (int i = 0; i < rank; i++) {
            for (int j = 0; j < rank; j++) {
                if (arr[i * rank + j] != 0) nZ++;
            }
        }
    }

    value = (int *)malloc(nZ * sizeof(int));
    rowPtr = (int *)malloc((rank + 1) * sizeof(int));
    colInd = (int *)malloc(nZ * sizeof(int));
    rowPtr[0] = 0;

    int countNZRow = 0;
    for (int i = 0; i < rank; i++) {
        for (int j = 0; j < rank; j++) {
            if (arr[i * rank + j] != 0) {
                value[countNZRow] = arr[i * rank + j];
                colInd[countNZRow] = j;
                countNZRow++;
            }
        }
        rowPtr[i+1] = countNZRow;
    }
}


// Function to find one norm upper bound in full-matrix format
double MatrixOperations::upperBoundOneNormFull() {

    double bound_value = 0;  
    double sum = 0;  
    for (int i = 0; i < rank; i++) {
        sum = 0;
        for (int j = 0; j < rank; j++) {
            sum += arr[i*rank + j];
        }
        if (sum > bound_value) bound_value = sum;
    }
    return bound_value;
}


// Function to find infinite norm upper bound in full-matrix format
double MatrixOperations::upperBoundInfNormFull() {

    double bound_value = 0;  
    double sum = 0;  
    for (int i = 0; i < rank; i++) {
        sum = 0;
        for (int j = 0; j < rank; j++) {
            sum += arr[j*rank + i];
        }
        if (sum > bound_value) bound_value = sum;
    }
    return bound_value;
}

// Function to find one norm upper bound in row-compressed format
double MatrixOperations::upperBoundOneNormSparse() {

    double bound_value = 0;  
    double sum = 0;  
    for (int i = 0; i < rank; i++) {
        sum = 0;
        for (int j = rowPtr[i]; j < rowPtr[i+1]; j++) {
            sum += value[j];
        }
        if (sum > bound_value) bound_value = sum;
    }
    return bound_value;
}

// Function to find infinite norm upper bound in row-compressed format
double MatrixOperations::upperBoundInfNormSparse() {

    double bound_value = 0;  
    double sum = 0;  
    for (int i = 0; i < rank; i++) {
        sum = 0;
        for (int j = rowPtr[i]; j < rowPtr[i+1]; j++) {
            sum += value[j];
        }
        if (sum > bound_value) bound_value = sum;
    }
    return bound_value;
}



#if 0
// Function to do row-permutation operation in sparse matrix format
// Input arguments: row i and row j (matrix is part of private member of the class)
void MatrixOperations::rowPermuteSparse(int i, int j) {
    cout << endl;

    int nZSizeOfFirst = rowPtr[i] - rowPtr[i-1];
    int nZSizeOfSecond = rowPtr[j] - rowPtr[j-1];


    int tempFirstArrayValue[nZSizeOfFirst];
    int tempSecondArrayValue[nZSizeOfSecond];
    int tempFirstArrayColInd[nZSizeOfFirst];
    int tempSecondArrayColInd[nZSizeOfSecond];

    int counter = 0;

    // Copy the value and col for first row in a temp array
    for (int k = rowPtr[i-1]; k < rowPtr[i]; k++) {
        tempFirstArrayValue[counter] = value[k];
        tempFirstArrayColInd[counter] = colInd[k];
        counter++;
    }

    counter = 0;

    // Copy the value and col for second row in a temp array
    for (int k = rowPtr[j-1]; k < rowPtr[j]; k++) {
        tempSecondArrayValue[counter] = value[k];
        tempSecondArrayColInd[counter] = colInd[k];
        counter++;
    }


    // shift original col and val array by difference in no of elements of both rows
    // if row1 has more elements than row2, array will shift leftwards
    // if row1 has less elements than row2, array will shift rightwards
    for (int k = rowPtr[i]; k < rowPtr[j] - 1; k++) {
        colInd[k - (nZSizeOfFirst - nZSizeOfSecond)] = colInd[k];
        value[k - (nZSizeOfFirst - nZSizeOfSecond)] = value[k];
    }

    counter = 0;
    for (int k = rowPtr[i - 1]; k < (rowPtr[i - 1] + nZSizeOfSecond); k++) {
        value[k] = tempSecondArrayValue[counter];
        colInd[k] = tempSecondArrayColInd[counter];
        counter++;
    }
    counter = 0;
    for (int k = rowPtr[j - 1]; k < (rowPtr[j - 1] + nZSizeOfFirst); k++) {
        value[k-1] = tempFirstArrayValue[counter];
        colInd[k-1] = tempFirstArrayColInd[counter];
        counter++;
    }

    for (int k = i; k < j; k++) {
        rowPtr[k] -= nZSizeOfFirst - nZSizeOfSecond;
    }

    cout << "Perumation performed in row-compressed format between " << i << " " << j << endl << endl;
    return;
}
#endif

// Constructor for small matrices where full-format matrix is known
// It loads the matrix in 'arr' along with other information
MatrixOperations::MatrixOperations(int *arr, int rank, long nZ = -1) {
    cout << endl;
    this->arr = arr;
    this->rank = rank;
    this->nZ = nZ;
    this->value = NULL;
    this->rowPtr = NULL;
    this->colInd = NULL;
}

// Destructor
MatrixOperations::~MatrixOperations() {
    if (this->arr) free(this->arr);
    if (this->value) free(this->value);
    if (this->rowPtr) free(this->rowPtr);
    if (this->colInd) free(this->colInd);
}

int main() {

    int arr1[5][5] = {
                    {1, 2, 0, 0, 3},
                    {4, 5, 6, 0, 0},
                    {0, 7, 8, 0, 9},
                    {0, 0, 0, 10, 0},
                    {11,0, 0, 0, 1}
                    };

    MatrixOperations *first = new MatrixOperations((int*)arr1, 5);
    first->createMatrix();
    first->printMatrixFull();

    cout << "One upper bound for full " << first->upperBoundOneNormFull() << endl;
    cout << "One upper bound for sparse " << first->upperBoundOneNormSparse() << endl;
    cout << "Inf upper bound for full " << first->upperBoundInfNormFull() << endl;
    cout << "Inf upper bound for sparse " << first->upperBoundInfNormSparse() << endl;

    return 0;
}


