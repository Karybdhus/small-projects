#include "deklarationen.h"

void showMenu()
{
    std::cout << "\n\n ------------------------- " << std::endl;
    std::cout << "|     Kontoverwaltung     |" << std::endl;
    std::cout << "|-------------------------|" << std::endl;
    std::cout << "| 1 - Nutzer anzeigen     |" << std::endl;
    std::cout << "| 2 - Konto auswaehlen    |" << std::endl;
    std::cout << "| 3 - Neues Konto anlegen |" << std::endl;
    std::cout << "| 4 - Konto schliessen    |" << std::endl;
    std::cout << "| 5 - Daten speichern     |" << std::endl;
    std::cout << "| 6 - Programm beenden    |" << std::endl;
    std::cout << " ------------------------- " << std::endl;
    std::cout << " Auswahl: ";
    return;
}

void subMenu(std::string firstName, std::string lastName)
{
    std::cout << "\n\nKontoinhaber: " << firstName << " " << lastName << std::endl;
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
}