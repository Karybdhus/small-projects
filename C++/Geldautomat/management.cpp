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
        delete current->data;
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
    Accountlist *newNode = new Accountlist;
    newNode->data = newAccount;
    newNode->next = nullptr;

    if (accounts == nullptr)
    {
        accounts = newNode;
    }
    else
    {
        Accountlist *current = accounts;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}