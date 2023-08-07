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
    float amount;
    std::cout << "Einzahlungsbetrag: ";
    amount = validInput<float>();

    if (amount < 0)
    {
        std::cout << "Ungültig. Betrag muss positiv sein" << std::endl;
        return false;
    }

    Account::balance += amount;
    return true;
}

bool Account::withdraw()
{
    float amount;
    std::cout << "Auszahlungsbetrag: ";
    amount = validInput<float>();

    if (amount < 0)
    {
        amount *= -1;
    }

    Account::balance -= amount;

    if (Account::balance < (0 - Account::credit))
    {
        std::cout << "Kreditrahmen überschritten. Auszahlung nicht möglich" << std::endl;
        Account::balance += amount;
        return false;
    }
    return true;
}

bool Account::setCredit()
{
    float newCredit;

    std::cout << "Neuer Kreditrahmen: ";
    newCredit = validInput<float>();
    if (newCredit > (Account::balance * 0.1))
    {
        std::cout << "Änderung nicht möglich. Darf 10% des Kontostandes nicht überschreiten" << std::endl;
        return false;
    }
    Account::credit = newCredit;

    return true;
}

bool Account::transfer(Account *recipient)
{
    float amount;
    std::cout << "Überweisungsbetrag: ";
    amount = validInput<float>();

    if (amount < 0)
    {
        std::cout << "Ungültig. Betrag muss positiv sein" << std::endl;
        return false;
    }

    Account::balance -= amount;

    if (Account::balance < (0 - Account::credit))
    {
        std::cout << "Kreditrahmen überschritten. Überweisung nicht möglich" << std::endl;
        Account::balance += amount;
        return false;
    }

    recipient->balance += amount;

    return true;
}