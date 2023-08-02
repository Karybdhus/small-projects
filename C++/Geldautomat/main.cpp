#include "deklarationen.h"

int main()
{
    int choice;
    std::string lastName, firstName;
    Management manager;

    while (true)
    {
        showMenu();
        std::cin >> choice;

        if (std::cin.fail() || choice < 1 || choice > 6)
        {
            std::cout << "Fehlerhafte Eingabe, bitte wiederholen" << std::endl;
            std::cin.clear();
            while (getc(stdin) != '\n')
                ;
            continue;
        }

        while (getc(stdin) != '\n')
            ;

        switch (choice)
        {
        case 1:
        {
            manager.showAccounts();
            break;
        }

        case 2:
        {
            std::cout << "\nKonto auswaehlen" << std::endl;
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
            manager.accountManagement(firstName, lastName);
            break;
        }

        case 3:
        {
            std::cout << "\nKonto anlegen" << std::endl;
            manager.addAccount();
            break;
        }

        case 4:
        {
            std::cout << "\nKonto wird entfernt" << std::endl;
            break;
        }

        case 5:
        {
            std::cout << "\nDaten werden gesichert" << std::endl;
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