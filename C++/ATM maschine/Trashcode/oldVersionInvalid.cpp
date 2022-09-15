#include <iostream>

using namespace std;

void showMenu();

class master
{
private:
    string Name;

protected:
    string Benutzer;
    float Kontostand{0.0};

public:
    master(string name)
    {
        Name = name;
    }

    int ATM()
    {
        int option;
        do
        {
            showMenu();
            {
                cout << "Option wählen: ";
                cin >> option;
                system("clear");
                switch (option)
                {
                case 1:
                    cout << "Guthaben: " << Kontostand << "€\n"
                         << endl;
                    break;
                case 2:
                    cout << "Einzahlungsbetrag: ";
                    float depositAmount;
                    cin >> depositAmount;
                    aenderung(depositAmount);
                    cout << endl;
                    break;
                case 3:
                    cout << "Auszahlungsbetrag: ";
                    float withdrawAmount;
                    cin >> withdrawAmount;
                    cout << endl;
                    if (withdrawAmount <= Kontostand)
                    {
                        withdrawAmount *= -1;
                        aenderung(withdrawAmount);
                    }
                    else
                    {
                        cout << "Verfügungsrahmen überschritten\n"
                             << endl;
                    }
                    break;
                case 4:
                    cout << "Überweisungsbetrag: ";
                    float transferAmount;
                    cin >> transferAmount;
                    Kontostand -= transferAmount;
                    transfer(transferAmount);
                case 5:
                    cout << "zurück zu Benutzerauswahl...\n"
                         << endl;
                    return 1;
                case 6:
                    cout << "beende...\n"
                         << endl;
                    return 3;
                default:
                    cout << "ungültige Eingabe\n"
                         << endl;
                    break;
                }
            }
        } while (option != 6);
        return 0;
    }

    float aenderung(float wert = 0.0)
    {
        Kontostand += wert;
        return Kontostand;
    }

    void transfer(float transferAmount)
    {
        int auswahl;
        bool ungueltig = true;
        do
        {
            cout << "1 - Franz Nowak\n2 - Nadine Nowak\n3 - zurück\n"
                 << endl
                 << "Empfänger wählen: ";
            cin >> auswahl;
            system("clear");
            switch (auswahl)
            {
            case 1:
                cout << "Überweisung an Franz Nowak: " << transferAmount << endl;
                //Nadine.aenderung(transferAmount);
                ungueltig = false;
                break;
            case 2:
                cout << "Überweisung an Nadine Nowak: " << transferAmount << "€" << endl;
                //Franz.aenderung(transferAmount);
                ungueltig = false;
                break;
            case 3:
                break;
            }
        } while (ungueltig);
    }
};

class user : public master
{
public:
    user(string name) : master(name)
    {
    }
};

void showMenu();
int Nutzermenu();
void transfer(float transferAmount);

int main()
{
    int i;
    user Franz("Franz Nowak");
    user Nadine("Nadine Nowak");

    while (i = Nutzermenu())
    {
        switch (i)
        {
        case 1:
            Franz.ATM();
            break;
        case 2:
            Nadine.ATM();
            break;
        default:
            cout << "beende...\n"
                 << endl;
            break;
        }
    }
}
int Nutzermenu()
{
    int auswahl;
    bool ungueltig = true;
    do
    {
        cout << "Angemeldete Nutzer:\n1 - Franz Nowak\n2 - Nadine Nowak\n3 - Ende\n"
             << endl
             << "Nutzer wählen: ";
        cin >> auswahl;
        system("clear");
        switch (auswahl)
        {
        case 1:
            cout << "Hallo Franz\n"
                 << endl;
            ungueltig = false;
            break;
        case 2:
            cout << "Hallo Nadine\n"
                 << endl;
            ungueltig = false;
            break;
        case 3:
            cout << "beende..." << endl;
            return 0;
        default:
            cout << "Bitte über Admin registrieren lassen.\n"
                 << endl;
            break;
        }
    } while (ungueltig);
    return auswahl;
}

void showMenu()
{
    cout << "Der virtuelle Geldbeutel\n"
         << "==============================\n"
         << "1 - Guthaben abfragen\n"
         << "2 - Geld einzahlen\n"
         << "3 - Geld auszahlen\n"
         << "4 - Geld überweisen\n"
         << "5 - zurück zur Benutzerauswahl\n"
         << "==============================" << endl;
}
