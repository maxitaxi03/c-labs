#include "Header.h"
#include <iostream>
using namespace std;


template<class T>
Matrix<T>::Matrix()
{
    rows = MAXROWS;
    cols = MAXCOLS;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            doubleArray[i][j] = '\0';
        }
    }
}

template <class T>
void Matrix<T>::printMatrix()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << doubleArray[i][j] << "   ";
        }
        cout << endl;
    }
}

template <class T>
void Matrix<T>::setMatrix(T otherArray[][MAXCOLS])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            doubleArray[i][j] = otherArray[i][j];
        }
    }
}

template <typename T>
void Matrix<T>::addMatrix(T otherArray[][MAXCOLS])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            doubleArray[i][j] += otherArray[i][j];
        }
    }
}

template <typename T>
void Matrix<T>::addMatrix(Matrix otherMatrix)
{
    addMatrix(otherMatrix.doubleArray);
}
template class Matrix <int>;
template class Matrix <char>;
template class Matrix <float>;
template class Matrix <string>;