#pragma once

#include <iostream>
#include <string>

class Account
{
private:
    float balance;
    float credit;
    std::string lastName;
    std::string firstName;

public:
    Account(float bal, float cr, const std::string last, const std::string first); // Konstruktor
    std::string getLastName();                                                     // zum Abfragen des Nachnamen
    std::string getFirstName();                                                    // zum Abfragen des Vornamen
    float getBalance();                                                            // zum Abfragen des Kontostandes
    bool changeBalance();                                                          // Es ist wichtig zu wissen ob das "changeBalance()" erfolgreich war.
    void changeCredit();
};

class Accountlist
{
private:
public:
    Account *data;     // hier kommt immer das eigentliche aktuelle Accountelement hin
    Accountlist *next; // hier ist dann immer das nächste Listenelement
};

class Management
{
private:
    Accountlist *accounts;

public:
    Management();
    ~Management();

    void addAccount();
};