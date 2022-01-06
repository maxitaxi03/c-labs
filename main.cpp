//
//  main.cpp
//  bankAccount
//
//  Created by Maximus Boxill on 04/01/2022.
//

#include <iostream>
#include <array>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include "bank_account.h"
using namespace std;

array<Account, 25> create_account();

int main(int argc, const char * argv[]) {
    // insert code here...
    Account maximus("Maximus", "Boxill", 19);
    array <Account, 25> arr = create_account();
    
    ofstream output;
    output.open("/Users/maximus/Library/Mobile Documents/com~apple~CloudDocs/Projects/Misc/bankAccount/bankAccount.txt");
    if (output.fail()) {
        cerr << "File didn't open";
        exit(1);
    }
    
//    maximus.set_accountNumber();
    maximus.deposit(10000);
    maximus.print();
    output << left << setw(10) << "FName" << setw(10) << "LName" << setw(10) << "Age" << setw(10) << "Balance" << setw(10) << "Account Number" << endl;
//    output << left << setw(10) <<maximus.get_fname() << setw(10) << maximus.get_lname() << setw(10) << maximus.get_age() << setw(10) << maximus.get_currBalance() << setw(10) << maximus.get_accountNumber() << endl;
    for (int i = 0; i < arr.size(); i++) {
        output << left << setw(10) << arr.at(i).get_fname() << setw(10) << arr.at(i).get_lname() << setw(10) << arr.at(i).get_age() << setw(10) << arr.at(i).get_currBalance() << setw(10) << arr.at(i).get_accountNumber() << endl;
    }
    output.close();
    
    return 0;
}


array <Account, 25> create_account() {
    ifstream input;
    array<Account, 25> account_container;
    
//    string account_details_container[25];
//    int length = sizeof(account_details_container) / sizeof(account_details_container[0]);
    input.open("/Users/maximus/Library/Mobile Documents/com~apple~CloudDocs/Projects/Misc/bankAccount/names.txt");

    if (input.fail()) {
        cerr << "Error opening names file. Please try again";
        exit(1);
    }
    else {
        string fname, lname, age, space1, space2;
        int new_age = 0;
        
        
        while (!input.eof()) {
            input >> fname >> space1 >> lname >> space2 >> age;
            stringstream stream(age);
            stream >> new_age;
            Account account_details(fname, lname, new_age);
            account_container.fill(account_details);
            
        }
    }
    input.close();
    return account_container;
}
