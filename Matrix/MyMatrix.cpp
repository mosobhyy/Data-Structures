#include "MyMatrix.h"

/* Class Member Functions Implementation */

template<class T>

bool MyMatrix<T>::addElementAt(int row, int col, int element)
{
    if (row < 0 || col < 0 || row > this->getRows() || col > this->getCols())
        return false;

    m[row][col] = element;
    return true;
}

template<class T>
bool MyMatrix<T>::getElementAt(int row, int col)
{
    if (row < 0 || col < 0 || row > this->getRows() || col > this->getCols())
        return false;
    cout << m[row][col] << endl;
    return true;
}

template<class T>
int MyMatrix<T>::getRows() const
{
    return rows;
}

template<class T>
int MyMatrix<T>::getCols() const
{
    return cols;
}

template<class T>
void MyMatrix<T>::setRows(int row)
{
    this->rows = row;
}

template<class T>
void MyMatrix<T>::setCols(int col)
{
    this->cols = col;
}

template<class T>
void MyMatrix<T>::displayMatrix()
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
            cout << m[i][j] << " ";
        cout << endl;
    }
}

template<class T>
MyMatrix<T>::MyMatrix(int rows, int cols)
{
    setRows(rows);
    setCols(cols);

    m = new T *[rows];

    for (int i = 0; i < rows; i++)
        m[i] = new T[cols];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            m[i][j] = {};
}

template<class T>
MyMatrix<T>::MyMatrix(const MyMatrix &obj)
{
    setRows(obj.getRows());
    setCols(obj.getCols());

    m = new T *[rows];

    for (int i = 0; i < rows; i++)
        m[i] = new T[cols];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            m[i][j] = obj.m[i][j];
}

template<class T>
MyMatrix<T>::~MyMatrix()
{
    for (int i = 0; i < rows; i++)
        delete[] m[i];
    delete[] m;
}