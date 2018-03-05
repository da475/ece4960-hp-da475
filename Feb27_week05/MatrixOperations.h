/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MatrixOperations.h
 * Author: Vishisht and Deepak
 *
 * Created on February 25, 2018, 8:54 PM
 */

#ifndef MATRIXOPERATIONS_H
#define MATRIXOPERATIONS_H

class MatrixOperations {
private:
    
    int rank;
    long nZ;
    int *arr;
    int *value;
    int *rowPtr;
    int *colInd;
    
public:

    // Constructor for small matrices where full-format matrix is known
    MatrixOperations(int *arr, int rank, long nZ);

    // Destructor
    ~MatrixOperations();

    // Function to print a matrix in full-matrix format
    void printMatrixFull();

    // Function to print a matrix in full-matrix format
    void printMatrixSparse();

    // Function to convert a matrix to row-compressed format
    void createMatrix();

    // Functions to find upper bounds
    double upperBoundOneNormFull();
    double upperBoundInfNormFull();
    double upperBoundOneNormSparse();
    double upperBoundInfNormSparse();

};

#endif /* MATRIXOPERATIONS */

