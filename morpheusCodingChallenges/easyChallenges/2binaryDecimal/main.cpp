#include <iostream>

#define MAX 10

using namespace std;

int main()
{
    unsigned int t, i;
    cin >> t;
    cin.ignore(1, '\n');
    char Zahl[t][MAX] = {0, 0};
    char max[t] = {0};

    for (i = 0; i < t; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            Zahl[i][j] = getchar();

            if (Zahl[i][j] == '\n')
                break;
        }
    }

    for (i = 0; i < t; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            if (Zahl[i][j] > max[i])
            {
                max[i] = Zahl[i][j];
            }
        }
    }

    cout << endl;

    for (i = 0; i < t; i++)
    {
        cout << max[i] << endl;
    }
    return 0;
}
