#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

template <typename T1>
void demoTemplate(Matrix<T1>& M, T1 array1[][MAXCOLS], T1 array2[][MAXCOLS]);

int main()
{
    string str1[MAXROWS][MAXCOLS] =
    {
   {"Congra", "y", "ar"},
   {"alm", "don", "La"}
    };
    string str2[MAXROWS][MAXCOLS] =
    {
   {"tulations", "ou", "e"},
   {"ost", "e    the", "b!"}
    };
    int arr1[MAXROWS][MAXCOLS] = {
        {1, 2, 3},
        {0, 0, 0}
    };
    int arr2[MAXROWS][MAXCOLS] = {
        {2, 4, 6},
        {9, 8, 7}
    };
    float darr1[MAXROWS][MAXCOLS] = {
        {2.3, 5.6, 6.5},
        {1.3, 2.8, 7.8}
    };
    float darr2[MAXROWS][MAXCOLS] = {
        {4.0, 2.9, 3.4},
        {10.0, 4.9, 5.9}
    };

    Matrix<string> stringMatrix;

    cout << "\nDemonstrating with string matrix:" << endl;
    demoTemplate(stringMatrix, str1, str2);

    Matrix<int> intMatrix;
    cout << endl;
    cout << "Demonstrating with int matrix: " << endl;
    demoTemplate(intMatrix, arr1, arr2);


    Matrix<float> floatMatrix;
    cout << endl;
    cout << "Demonstrating with float matrix: " << endl;
    demoTemplate(floatMatrix, darr1, darr2);
    cout << "\n" << endl;
    return 0;
}


template <typename T1>
void demoTemplate(Matrix<T1>& M, T1 array1[][MAXCOLS], T1 array2[][MAXCOLS])
{
    M.setMatrix(array1);
    cout << "\nMatrix set to first array" << endl;
    M.printMatrix();

    M.addMatrix(array2);
    cout << "\nMatrix incremented by second array" << endl;
    M.printMatrix();
}
