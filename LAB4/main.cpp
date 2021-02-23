#include <iostream>
#include <string>
#include "matrix.h"

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
    int arr1[MAXROWS][MAXCOLS] ={
        {1, 2, 3},
        {0, 0, 0}
    };
    int arr2[MAXROWS][MAXCOLS]={
        {0, 0, 0},
        {1, 2, 3}
    };

    Matrix<string> stringMatrix;
   
    cout << "\nDemonstrating with string matrix:" << endl;
    demoTemplate(stringMatrix, str1, str2);

    Matrix<int> intMatrix;
    cout << "Demonstrating with int matrix: "<<endl;
    demoTemplate(intMatrix, arr1, arr2);
   
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
template class Matrix <int>;
template class Matrix <char>;
template class Matrix <float>;
template class Matrix <string>;