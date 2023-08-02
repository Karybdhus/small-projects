#include "deklarationen.h"

Account::Account(float bal, float cr, std::string last, std::string first)
    : balance(bal), credit(cr), lastName(last), firstName(first)
{
}

std::string Account::getLastName()
{
    return lastName;
}

std::string Account::getFirstName()
{
    return firstName;
}

float Account::getBalance()
{
    return balance;
}

float Account::getCredit()
{
    return credit;
}

bool Account::deposit()
{
    return true;
}

bool Account::withdraw()
{
    return true;
}

bool Account::setCredit()
{
    return true;
}

bool Account::transfer()
{
    return true;
}