#include <iostream>

using namespace std;

int main()
{
    int n;
    int tab[20];

    int m;
    int i = 0;
    do {
        do {
            cin >> n;
            if (n > 2 && n < 1000000)
                tab[i] = n;
            i++;
        } while (n != 0);

    } while (n != 0);

    cout << endl;


    for (int j = 0; j < i - 1; j++)
    {
        int k = 2;
        n = tab[j];

        cout << n << ": ";

        while (n > 1)
        {
            while (n % k == 0)
            {
                cout << k << " ";
                n /= k;
            }
            k++;
        }
        cout << endl;
    }

    return 0;
}