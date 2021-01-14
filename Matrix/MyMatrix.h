#ifndef MATRIX_MYMATRIX_H
#define MATRIX_MYMATRIX_H

#include "iostream"

using namespace std;

template<class T>
class MyMatrix
{
    /* Private Attributes */
    T **m;
    int rows, cols;

public:

    /* Public Methods */
    bool addElementAt(int row, int col, int element); //adds an element elem at the specified row r, and column c

    bool getElementAt(int row, int col); //gets an element elem at the specified row r, and column c

    /* Getter & Setters */
    int getRows() const; //returns number of rows

    int getCols() const; //returns number of columns

    void setRows(int row);

    void setCols(int col);

    void displayMatrix(); //displays the 2D array to the screen

    /* Constructors */
    MyMatrix(int row, int col); //Constructor takes matrix dimensions
    MyMatrix(const MyMatrix &obj);  //Copy Constructor

    /* Destructor to free memory */
    ~MyMatrix();
};


#endif //MATRIX_MYMATRIX_H
