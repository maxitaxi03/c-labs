//
//  bank_account.h
//  bankAccount
//
//  Created by Maximus Boxill on 04/01/2022.
//
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include<iomanip>
#include<random>
#include<chrono>
#define minNumber 00000000
#define maxNumber 99999999
#ifndef bank_account_h
#define bank_account_h
using namespace std;

class Person {
private:
    string fname;
    string lname;
    int age;
    
public:
    Person();
    Person(string, string, int);
    string get_fname();
    string get_lname();
    int get_age();
    void set_fname(string);
    void set_lname(string);
    void set_age(int);
    
};

class Account: public Person {
private:
    long int accountNumber = 0;
    float currBalance = 0;
public:
    Account();
    Account(string, string, int);
    long int get_accountNumber();
    int get_currBalance();
    void deposit(int cash);
    void withdrawl(int cash);
    void print();
    void set_accountNumber();
    int random_account_number_generator(int, int);
};


#endif /* bank_account_h */
