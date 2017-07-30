#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>
#include <sstream>
#include <limits>

using namespace std;


class Account{
private:
    bool userExists;
    string inputCheck;
    int input;
    int balance;
    string username;
    string password;
public:
    Account();
    void makeAccount();
};

#endif // ACCOUNT_H
