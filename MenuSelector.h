#ifndef MENUSELECTOR_H
#define MENUSELECTOR_H
#include "account.h"
using namespace std;

class MenuSelector {
private:
    Account newAccount;
    bool keepGoing;
    bool foundUser;
    int input;
    int balance;
    string username;
    string password;

public:
    MenuSelector();
    void menu1();
    void menu2(const string& username, const string& password);
};

#endif // MENUSELECTOR
