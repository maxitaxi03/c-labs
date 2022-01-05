//
//  bank_account.cpp
//  bankAccount
//
//  Created by Maximus Boxill on 04/01/2022.
//

#include <iostream>
#include <iomanip>
#include<fstream>
#include<random>
#include<string>
#include<chrono>
#include "bank_account.h"
#define minNumber 00000000
#define maxNumber 99999999
using namespace std;


Person::Person() {
    this->fname = "";
    this->lname = "";
    this->age = 0;
}
Person::Person(string fname, string lname, int age) {
    this->fname = fname;
    this->lname = lname;
    this->age = age;
}
void Person::set_fname(string fname) {
    this->fname = fname;
}

void Person::set_lname(string lname) {
    this->lname = lname;
}

void Person::set_age(int age) {
    this->age = age;
}

string Person::get_fname() {
    return this->fname;
}

string Person::get_lname() {
    return this->lname;
}

int Person::get_age() {
    return this->age;
}

Account::Account() {
    this->set_fname("");
    this->set_fname("");
    this->set_age(0);
}

Account::Account(string fname, string lname, int age) {
    this->set_fname(fname);
    this->set_lname(lname);
    this->set_age(age);
}

int Account::get_currBalance() {
    return this->currBalance;
}

void Account::set_accountNumber() {
    int lower_limit = 00000000, upper_limit = 999999999;
    int num = random_account_number_generator(lower_limit, upper_limit);
    this->accountNumber = num;
}

long int Account::get_accountNumber() {
    return this->accountNumber;
}

void Account::deposit(int cash) {
    this->currBalance += cash;
}

void Account::withdrawl(int cash) {
    if (cash > this->currBalance) {
        cerr << "Sorry, you have insufficient funds; yuh break bruddah" << endl;
    }
    else
        currBalance -= cash;
}

void Account::print() {
    cout << left << setw(15) << this->get_fname() << setw(15) << this->get_lname() << setw(15) << this->currBalance << endl;
}

bool Account::get_hasAccount() {
    return this->hasAccount;
}

bool Account::check_has_account() {
    bool check;
    return check = (this->accountNumber == 0) ? false : true;
}

int Account::random_account_number_generator(int lower_limit, int upper_limit) {
    unsigned int seed = chrono::steady_clock::now().time_since_epoch().count();
    default_random_engine ranGen(seed);
    uniform_int_distribution<int>random_number(lower_limit, upper_limit);
    return random_number(ranGen);
}


