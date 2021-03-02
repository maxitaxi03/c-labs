#pragma once
#ifndef HEADER
#define HEADER
#include <vector>
#include <fstream>
using namespace std;

class Person{
    int code, age;
    string first_name,last_name, city;
public:
    Person(int co, string fn, string ln, string ci, int ag);
    int getCode();
    int getAge();
    string getFname();
    string getLname();
    string getCity();
    void setCode(int c);
    void setAge(int a);
    void setFname(string f);
    void setLname(string l);
    void setCity(string c);

};
Person::Person(int co, string fn, string ln, string ci, int ag) {
    code = co;
    first_name = fn;
    last_name = ln;
    city = co;
    age = ag;
}
int Person::getCode() {
    return code;
}
int Person::getAge() {
    return age;
}
string Person::getFname() {
    return first_name;
}
string Person::getLname() {
    return last_name;
}
string Person::getCity() {
    return city;
}
void Person::setCode(int c) {
    code = c;
}
void Person::setAge(int a) {
    age = a;
}
void Person::setFname(string f) {
    first_name = f;
}
void Person::setLname(string l) {
    last_name = l;
}
void Person::setCity(string c) {
    city = c;
}

class Members{
    vector<Person>mem;

public:
    vector<Person>& getMem(){
        return mem;
    }
    Members(){
        int co, a;
        string fn, ln, c;
        ifstream datafile;
        datafile.open("members.txt");
        if (datafile.fail()){
            cerr << "There was an error opening this file.";
            exit(1);
        }
        getline(datafile, fn);
        while (datafile >> co >> fn >> ln >> c >> a) {
            Person p(co, fn, ln, c, a);
            mem.push_back(p);
        }


    }

};
#endif