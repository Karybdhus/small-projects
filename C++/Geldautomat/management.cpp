#include "deklarationen.h"

Management::Management() : accounts(nullptr)
{
}

Management::~Management()
{
    Accountlist *current = accounts;
    while (current != nullptr)
    {
        Accountlist *next = current->next;
        delete current;
        current = next;
    }
}

void Management::addAccount()
{
    float balance, credit;
    std::string lastName, firstName;

    std::cout << "Nachname: ";
    std::cin >> lastName;
    std::cout << "Vorname: ";
    std::cin >> firstName;
    std::cout << "Ersteinzahlung: ";
    std::cin >> balance;
    credit = balance * 0.1;

    Account *newAccount = new Account(balance, credit, lastName, firstName);
    newAccount->next = accounts;
    accounts = newAccount;
}