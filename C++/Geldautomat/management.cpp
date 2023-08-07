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
        balance = validInput<float>();
        if (balance < 0)
        {
            std::cout << "\nFehlerhafte Eingabe. Betrag muss mindestens 0€ sein." << std::endl;
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

        choice = validInput<int>();

        if (choice < 1 || choice > 6)
        {
            std::cout << "\nFehlerhafte Eingabe, bitte wiederholen" << std::endl;
            continue;
        }

        switch (choice)
        {
        case 1:
        {
            std::cout << "\nKontoinhaber: " << firstName << " " << lastName << std::endl;
            std::cout << std::fixed << std::showpoint << std::setprecision(2);
            std::cout << "Kontostand: " << account->getBalance() << "€" << std::endl;
            break;
        }

        case 2:
        {
            if (account->deposit())
            {
                std::cout << "\nEinzahlung erfolgreich" << std::endl;
                std::cout << "Neuer Kontostand: " << account->getBalance() << "€" << std::endl;
            }
            break;
        }

        case 3:
        {
            if (account->withdraw())
            {
                std::cout << "\nAuszahlung erfolgreich" << std::endl;
                std::cout << "Neuer Kontostand: " << account->getBalance() << "€" << std::endl;
            }
            break;
        }

        case 4:
        {
            Account *recipient;
            std::string lastName, firstName;

            std::cout << "\nEmpfängerkonto angeben";
            getLastNameAndFirstName(lastName, firstName);

            if ((recipient = findAccount(lastName, firstName)) == nullptr)
            {
                std::cout << "Empfängerkonto nicht vorhanden.\n"
                          << std::endl;
                return;
            }

            if (account->transfer(recipient))
            {
                std::cout << "\nÜberweisung erfolgreich" << std::endl;
                std::cout << "Neuer Kontostand: " << account->getBalance() << "€" << std::endl;
            }
            break;
        }

        case 5:
        {
            if (account->setCredit())
            {
                std::cout << "\nÄnderung erfolgreich" << std::endl;
                std::cout << "Neuer Kreditrahmen: " << account->getCredit() << "€" << std::endl;
            }
            break;
        }

        case 6:
        {
            std::cout << "\nZurück zum Hauptmenu" << std::endl;
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

bool Management::hasAccounts()
{
    return accounts != nullptr;
}

void Management::saveAccounts()
{
    std::ofstream outputFile;
    std::string fileName = "Kontoliste.csv";
    Accountlist *current = accounts;

    outputFile.open(fileName);

    if (!outputFile.is_open())
    {
        std::cerr << "Fehler beim öffnen der Datei: " << fileName << std::endl;
        return;
    }

    while (current != nullptr)
    {
        outputFile << current->data->getLastName() << ";" << current->data->getFirstName() << ";" << current->data->getBalance() << ";" << current->data->getCredit() << std::endl;
        current = current->next;
    }
    outputFile.close();
    return;
}

void Management::loadAccounts()
{
    std::ifstream inputFile;
    std::string fileName;
    std::string line;
    int counter = 0;

    std::cout << "Dateinamen eingeben: ";
    fileName = validInput<std::string>();

    inputFile.open(fileName);

    if (!inputFile.is_open())
    {
        std::cerr << "Fehler beim Öffnen der Datei " << fileName << std::endl
                  << "Keine Daten geladen" << std::endl;
        return;
    }

    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        std::string lastName, firstName;
        std::string token;
        float balance, credit;

        if (std::getline(iss, token, ';'))
        {
            lastName = token;
        }

        if (std::getline(iss, token, ';'))
        {
            firstName = token;
        }

        if (std::getline(iss, token, ';'))
        {
            balance = std::stof(token);
        }
        if (std::getline(iss, token, ';'))
        {
            credit = std::stof(token);
        }

        if (iss.fail())
        {
            std::cerr << "Fehler beim Lesen der Daten" << std::endl;
            return;
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
        counter++;
    }
    inputFile.close();
    std::cout << counter << " Accounts erfolgreich eingelesen" << std::endl;
    return;
}