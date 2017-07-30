#include "account.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>
#include <sstream>
#include <limits>

using namespace std;
Account::Account(){};

void Account::makeAccount()
{
    ofstream myfile;
    myfile.open("userinfo.txt", ios::app); //append the text file
    cout << "Please Create a Username: ";
    //string inputCheck;//a string to compare name
    cin >> inputCheck;

    ifstream userCheck; // a input file stream variable
    userCheck.open("userinfo.txt"); //Open the file stream
    //check to see the if the username already exists.
    if (userCheck.is_open()) {
        userExists = false;
        while (userCheck >> username >> password) {
            if (inputCheck == username) {
                userExists = true;
                break;
                userCheck.close();
                myfile.close();
            }
        }
        if (userExists) {
            cout << "User already exists" << endl;
            userCheck.close();
            myfile.close();
        }

        else {
            cout << "Please Create a Password: ";
            cin >> password;
            balance = 0;
            myfile << inputCheck << ' ' << password << ' ' << balance << endl;
            myfile.close();
            userCheck.close();
            cout << "User account '" << inputCheck << "' has been created" << endl;
        } //ends create a password else
    } //ends if userCheck is open
};
