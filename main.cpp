//
//  main.cpp
//  bankAccount
//
//  Created by Maximus Boxill on 04/01/2022.
//

#include <iostream>
#include "bank_account.h"
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    Account maximus("Maximus", "Boxill", 19);
    ofstream output;
    output.open("bankAccount.txt");
    if (output.fail()) {
        cerr << "File didn't open";
        exit(1);
    }
    output << maximus.get_fname() << maximus.get_lname() << maximus.get_age() << maximus.get_currBalance() << maximus.get_accountNumber() << endl;
    maximus.set_accountNumber();
    maximus.deposit(10000);
    maximus.print();
    output.close();
    return 0;
}
