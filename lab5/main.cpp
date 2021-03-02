#include<iostream>
#include "member.h"
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;
int main(){
    int age;

    cout << "Please enter some age please: ";
    cin >> age;

    Members obj;
    vector<Person>::iterator i;

    for (i = obj.getMem().begin(); i != obj.getMem().end(); i++){
        cout << left << setw(15) << " " <<(*i).getFname();
    }
}