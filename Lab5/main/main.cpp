#include<iostream>
#include "member.h"
#include <vector>
#include<string>
#include <iomanip>
#include <fstream>
using namespace std;
int main() {
    int age;

    cout << "Please enter some age please: ";
    cin >> age;

    Members obj;
    vector<Person>::iterator i;

    
    for (i = obj.getMem().begin(); i != obj.getMem().end(); i++) {
        if (age < (*i).getAge()) {
            cout << left << setw(15) << (*i).getFname() << setw(15) << (*i).getLname() << setw(15) << (*i).getCity() << setw(15) << (*i).getAge() << endl;
        }
    }
    return 0;
}