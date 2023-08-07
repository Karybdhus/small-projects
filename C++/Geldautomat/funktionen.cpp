#include "deklarationen.h"

template <>
std::string validInput()
{
    std::string input;
    while (true)
    {
        std::getline(std::cin, input);
        if (std::cin.fail() || input.empty())
        {
            std::cout << "\nFehlerhafte Eingabe. Bitte wiederholen" << std::endl;
            std::cin.clear();
            while (std::cin.get() != '\n')
                ;
        }
        else if (input.length() > MAX_LENGTH)
        {
            input = input.substr(0, MAX_LENGTH);
            break;
        }
        else
        {
            break;
        }
    }
    return input;
}

void showMenu()
{
    std::cout << "\n ------------------------- " << std::endl;
    std::cout << "|     Kontoverwaltung     |" << std::endl;
    std::cout << "|-------------------------|" << std::endl;
    std::cout << "| 1 - Nutzer anzeigen     |" << std::endl;
    std::cout << "| 2 - Konto auswaehlen    |" << std::endl;
    std::cout << "| 3 - Neues Konto anlegen |" << std::endl;
    std::cout << "| 4 - Konto schliessen    |" << std::endl;
    std::cout << "| 5 - Daten speichern     |" << std::endl;
    std::cout << "| 6 - Daten extern laden  |" << std::endl;
    std::cout << "| 7 - Programm beenden    |" << std::endl;
    std::cout << " ------------------------- " << std::endl;
    std::cout << " Auswahl: ";
    return;
}

void subMenu(std::string firstName, std::string lastName)
{
    std::cout << "\nKontoinhaber: " << firstName << " " << lastName << std::endl;
    std::cout << "----------------------------" << std::endl;
    std::cout << "1 - Kontostand anzeigen" << std::endl;
    std::cout << "2 - Betrag einzahlen" << std::endl;
    std::cout << "3 - Betrag abheben" << std::endl;
    std::cout << "4 - Ueberweisung" << std::endl;
    std::cout << "5 - Kreditrahmen aendern" << std::endl;
    std::cout << "6 - Zurueck" << std::endl;
    std::cout << "----------------------------" << std::endl;
    std::cout << "Auswahl: ";
    return;
}

void getLastNameAndFirstName(std::string &lastName, std::string &firstName)
{
    std::cout << "\nNachname: ";
    lastName = validInput<std::string>();

    std::cout << "Vorname: ";
    firstName = validInput<std::string>();
}