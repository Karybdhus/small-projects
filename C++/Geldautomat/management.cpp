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
    float balance{-1}, credit;
    std::string lastName, firstName;

    std::cout << "Nachname: ";
    std::getline(std::cin, lastName);
    if (lastName.length() > MAX_LENGTH)
    {
        lastName = lastName.substr(0, MAX_LENGTH);
    }
    std::cout << "Vorname: ";
    std::getline(std::cin, firstName);
    if (firstName.length() > MAX_LENGTH)
    {
        firstName = firstName.substr(0, MAX_LENGTH);
    }
    
    while (balance < 0)
    {
        std::cout << "Ersteinzahlung: ";
        std::cin >> balance;
        if (std::cin.fail() || balance < 0)
        {
            std::cout << "Fehlerhafte Eingabe. Betrag muss mindestens 0€ sein." << std::endl;
            std::cin.clear();
            while (getc(stdin) != '\n')
                ;
        }
    }
    credit = balance * 0.1;

    Account *newAccount = new Account(balance, credit, lastName, firstName);
    Accountlist *newNode = new Accountlist(newAccount);
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

void Management::showAccounts()
{
    Accountlist *current = accounts;
    if (current == nullptr)
    {
        std::cout << "\nKeine Konten vorhanden." << std::endl;
        return;
    }
    std::cout << "\nKontoliste:\n" << std::endl;
    std::cout << std::left;
    std::cout << " -----------------------------------------" << std::endl;
    std::cout << std::setw(21) << "|Nachname" << std::setw(21) << "|Vorname" << "|" << std::endl;
    std::cout << "|--------------------|--------------------|" << std::endl;
    while (current != nullptr)
    {
        std::cout << "|" << std::setw(20) << current->data->getLastName() << "|" << std::setw(20) << current->data->getFirstName() << "|" << std::endl;
        current = current->next;
    }
    std::cout << " -----------------------------------------" << std::endl;
}