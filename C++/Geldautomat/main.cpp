#include "deklarationen.h"

int main()
{
    int choice;
    std::string lastName, firstName;
    Management manager;

    while (true)
    {
        showMenu();
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
            if(!manager.hasAccounts())
            {
                std::cout << "\nKeine Konten vorhanden" << std::endl;
                break;
            }
            manager.showAccounts();
            break;
        }

        case 2:
        {
            if(!manager.hasAccounts())
            {
                std::cout << "\nKeine Konten vorhanden" << std::endl;
                break;
            }
            std::cout << "\nKonto auswaehlen" << std::endl;
            getLastNameAndFirstName(lastName, firstName);
            manager.accountManagement(firstName, lastName);
            break;
        }

        case 3:
        {
            std::cout << "\nKonto wird angelegt" << std::endl;
            manager.addAccount();
            break;
        }

        case 4:
        {
            if(!manager.hasAccounts())
            {
                std::cout << "\nKeine Konten vorhanden" << std::endl;
                break;
            }
            std::cout << "\nKonto wird entfernt" << std::endl;
            manager.deleteAccount();
            break;
        }

        case 5:
        {
            if(!manager.hasAccounts())
            {
                std::cout << "\nKeine Konten vorhanden" << std::endl;
                break;
            }
            std::cout << "\nDaten werden gesichert" << std::endl;
            manager.saveAccounts();
            break;
        }

        case 6:
        {
            std::cout << "\nProgramm wird beendet" << std::endl;
            return 0;
        }
        }
    }

    return 0;
}