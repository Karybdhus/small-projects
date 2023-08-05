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

    getLastNameAndFirstName(lastName, firstName);

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

    if (balance < 1000)
    {
        credit = 0;
    }
    else if (balance < 5000)
    {
        credit = 200;
    }
    else
    {
        credit = 500;
    }

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

    std::cout << "\nKontoliste:\n"
              << std::endl;
    std::cout << std::left;
    std::cout << " -----------------------------------------" << std::endl;
    std::cout << std::setw(21) << "|Nachname" << std::setw(21) << "|Vorname"
              << "|" << std::endl;
    std::cout << "|--------------------|--------------------|" << std::endl;
    while (current != nullptr)
    {
        std::cout << "|" << std::setw(20) << current->data->getLastName() << "|" << std::setw(20) << current->data->getFirstName() << "|" << std::endl;
        current = current->next;
    }
    std::cout << " -----------------------------------------" << std::endl;
}

Account *Management::findAccount(const std::string &lastName, const std::string &firstName)
{
    Accountlist *current = accounts;
    while (current != nullptr)
    {
        if (current->data->getLastName() == lastName && current->data->getFirstName() == firstName)
        {
            return current->data;
        }
        current = current->next;
    }
    return nullptr;
}

void Management::accountManagement(std::string firstName, std::string lastName)
{
    int choice;
    Account *account;
    if ((account = findAccount(lastName, firstName)) == nullptr)
    {
        std::cout << "Konto nicht vorhanden.\n"
                  << std::endl;
        return;
    }
    while (true)
    {
        subMenu(firstName, lastName);
        std::cin >> choice;

        if (std::cin.fail() || choice < 1 || choice > 6)
        {
            std::cout << "Fehlerhafte Eingabe, bitte wiederholen" << std::endl;
            std::cin.clear();
            while (getc(stdin) != '\n')
                ;
            continue;
        }
        switch (choice)
        {
        case 1:
        {
            std::cout << "Kontoinhaber: " << firstName << " " << lastName << std::endl;
            std::cout << std::fixed << std::showpoint << std::setprecision(2);
            std::cout << "Kontostand: " << account->getBalance() << "€" << std::endl;
            break;
        }

        case 2:
        {
            if (account->deposit())
            {
                std::cout << "Einzahlung erfolgreich" << std::endl;
                std::cout << "Neuer Kontostand: " << account->getBalance() << "€" << std::endl;
            }
            break;
        }

        case 3:
        {
            if (account->withdraw())
            {
                std::cout << "Auszahlung erfolgreich" << std::endl;
                std::cout << "Neuer Kontostand: " << account->getBalance() << "€" << std::endl;
            }
            break;
        }

        case 4:
        {
            if (account->transfer())
            {
                std::cout << "Überweisung erfolgreich" << std::endl;
                std::cout << "Neuer Kontostand: " << account->getBalance() << "€" << std::endl;
            }
            break;
        }

        case 5:
        {
            if (account->setCredit())
            {
                std::cout << "Änderung erfolgreich" << std::endl;
                std::cout << "Neuer Creditrahmen: " << account->getCredit() << "€" << std::endl;
            }
            break;
        }

        case 6:
        {
            std::cout << "Zurück zum Hauptmenu" << std::endl;
            return;
        }
        }
    }
    return;
}

void Management::deleteAccount()
{
    Account *account;
    Accountlist *current = accounts;
    Accountlist *prev = nullptr;
    std::string lastName, firstName;

    std::cout << "\nKonto auswaehlen" << std::endl;
    getLastNameAndFirstName(lastName, firstName);

    if ((account = findAccount(lastName, firstName)) == nullptr)
    {
        std::cout << "Konto nicht vorhanden.\n"
                  << std::endl;
        return;
    }

    while (current != nullptr)
    {
        if (current->data->getLastName() == lastName && current->data->getFirstName() == firstName)
        {
            if (prev == nullptr)
            {
                accounts = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            delete current->data;
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
    return;
}