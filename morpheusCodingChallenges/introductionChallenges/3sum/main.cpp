#include <iostream>

using namespace std;

int main()
{
    int n, sum{0};
    cin >> n;
    int a[n] = {0};

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }

    cout << sum << endl;

    return 0;
}
