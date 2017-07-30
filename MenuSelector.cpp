#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>
#include <sstream>
#include <limits>
#include "MenuSelector.h"

using namespace std;
MenuSelector::MenuSelector(){};

void MenuSelector::menu1()
{
    while (keepGoing) {
        cout << ("1.Login\n2.Create Username and Password\n3.Exit") << endl;
        cin >> input;
        ///////////////////////////////////////////////////////////
        if (input == 1) { //LOGIN!!!
            //open the file
            ifstream user("userinfo.txt"); //CRETE IFSTREAM
            if (user.is_open()) {
                //get the username
                string checkUser;
                string checkPass;
                cout << "Enter username: " << endl;
                cin >> checkUser;
                bool foundUser = false;
                while (user >> username >> password >> balance) {
                    if (checkUser == username) {
                        foundUser = true;
                        user.close();
                        break;
                    }
                }
                if (foundUser) {
                    cout << "Password: " << endl;
                    cin >> checkPass; //get user input
                    if (checkPass == password) { //if the password is correct
                        cout << "Welcome back, " << username << endl; //User is logged in
                        //menu2(checkUser, checkPass);// <--------  LOOK HERE NIGGA!*!*!*!*!*!*!*!*!*
                        user.close();
                        foundUser = false;
                        menu2(checkUser, checkPass);
                        //put in the menu 2 function
                    }
                    else if (checkPass != password) { //If pass is incorrect
                        cout << "Password incorrect." << endl; //Denied
                        user.close();
                    } //end else if
                } //end if
                else {
                    cout << "Error, could not find user" << endl;
                    user.close();
                } //end if is open
            }

            else {
                cout << "Unable to open file" << endl;
            }
            user.close();
        }
        //end input 1

        //end first conditional statement
        ///////////////////////////////////////////////////////////////////////
        else if (input == 2) {
            ;
            newAccount.makeAccount();
        }
        else if (input == 3) {
            keepGoing = false;
        }
        else if (!(cin >> input)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Input" << endl;
        }
    }
}
void MenuSelector::menu2(const string& username, const string& password)
{
    bool loggedIn;
    loggedIn = true;
    string line;
    string checkUser = username;
    string checkPass = password;
    int currentBalance;

    while (loggedIn) {
        cout << "1.Check Balance\n2.Deposit\n3.Withdraw\n4.Logout" << endl;
        cin >> input;
        if (input == 1) {
            string checkUser = username; //set checkUser var equal to username var
            ifstream myfile("userinfo.txt");
            while (myfile >> checkUser >> checkPass >> balance) {
                if (checkUser == username) {
                    cout << "Current Balance: " << endl;
                    cout << "$" << balance << endl;
                    myfile.close();
                }
            }
        }
        else if (input == 2) { //deposit
            string checkUser = username; //set checkUser var equal to username var
            string checkPass = password;
            ofstream outfile("pleasework.txt");
            ifstream infile("userinfo.txt"); //CREATING IFSTREAM
            string u, p, b;
            int deposit;

            cout << "How much do you want to deposit?" << endl;
            //cin>>deposit;

            if (!(cin >> deposit)) { //If the input is not equal to the data type of deposit
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Input" << endl;
            }
            else {
                while (infile >> u >> p >> b) {
                    //cout<<"PLeae"<<endl;
                    //cout<<u<<' '<<p<<' '<<b<<endl;
                    if (checkUser == u) {
                        int newBalance;

                        //cout<<"Current Balance: $"<<b<<endl;
                        //cout<<"Enter new balance: ";

                        cout << "Your amount of $" << deposit << " has been added to your account" << endl;
                        int fileBalance;
                        stringstream convert(b); //object from the class stringstream
                        convert >> fileBalance; //the objects has the value of B and
                        newBalance = fileBalance + deposit;
                        outfile << checkUser << ' ' << checkPass << ' ' << newBalance << endl;
                    }
                    else {
                        outfile << u << ' ' << p << ' ' << b << endl;
                        //end else
                    }
                } //end while
                infile.close();
                outfile.close();
                remove("userinfo.txt");
                char oldname[] = "pleasework.txt";
                char newname[] = "userinfo.txt";
                rename(oldname, newname);
            }
        }
        else if (input == 3) {
            string checkUser = username; //set checkUser var equal to username var
            string checkPass = password;
            ofstream outfile("pleasework.txt");
            ifstream infile("userinfo.txt"); //CREATING IFSTREAM
            string u, p, b;
            int withdraw;
            cout << "How much do you want to withdraw?" << endl;

            if (!(cin >> withdraw)) { //If the input is not equal to the data type of deposit
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Input" << endl;
            }
            else {
                while (infile >> u >> p >> b) {
                    if (checkUser == u) {
                        int newBalance;
                        int fileBalance;
                        stringstream convert(b); //object from the class stringstream
                        convert >> fileBalance; //the objects has the value of B and
                        newBalance = fileBalance - withdraw;

                        if (newBalance < 0) {
                            cout << "Error: Balance cannot go below zero" << endl;
                            newBalance = fileBalance;
                        }
                        else if (newBalance >= 0) {
                            cout << "Your amount of $" << withdraw << " has been withdrawn your account" << endl;
                            outfile << checkUser << ' ' << checkPass << ' ' << newBalance << endl;
                        }
                    }
                    else { //second part of original if statement
                        outfile << u << ' ' << p << ' ' << b << endl;
                    } //end else
                } //end while
                infile.close();
                outfile.close();
                remove("userinfo.txt");
                char oldname[] = "pleasework.txt";
                char newname[] = "userinfo.txt";
                rename(oldname, newname);
            }
        }
        else if (input == 4) {
            cout << "Thank you, " << username << ". You have successfully logged out" << endl;
            loggedIn = false;
            //        foundUser = false;
            menu1();
        }
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Input" << endl;
        }
    }
};



