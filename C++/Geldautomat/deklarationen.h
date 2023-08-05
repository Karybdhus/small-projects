#pragma once

#include <iostream>
#include <string>
#include <iomanip>

#define MAX_LENGTH 20

void showMenu();
void subMenu(std::string firstName, std::string lastName);
void accountManagement(std::string firstName, std::string lastName);
void getLastNameAndFirstName(std::string &lastName, std::string &firstName);

class Account
{
private:
    float balance;
    float credit;
    std::string lastName;
    std::string firstName;

public:
    Account(float bal, float cr, const std::string last, const std::string first);
    std::string getLastName();
    std::string getFirstName();
    float getBalance();
    float getCredit();
    bool deposit();
    bool withdraw();
    bool setCredit();
    bool transfer();
};

class Accountlist
{
private:
public:
    Account *data;
    Accountlist *next;
    Accountlist(Account *acc);
};

class Management
{
private:
    Accountlist *accounts;

public:
    Management();
    ~Management();

    void addAccount();
    void deleteAccount();
    void showAccounts();
    void accountManagement(std::string firstName, std::string lastName);
    Account *findAccount(const std::string &lastName, const std::string &firstName);
};