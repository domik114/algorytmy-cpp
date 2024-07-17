#include <iostream>

using namespace std;

int Ciag_Licz(int* tab, int n)
{
    int* pom = new int[n];
    int i;
    int j;
    int max = 0;

    for (i = 0; i < n; i++)
        pom[i] = 1;

    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
            if (tab[i] > tab[j] && pom[i] < pom[j] + 1) 
                pom[i] = pom[j] + 1;

    /*cout << endl;

    for (i = 0; i < n; i++)
        cout << pom[i] << " ";*/

    for (i = 0; i < n; i++)
        if (max < pom[i]) 
            max = pom[i];

    delete[] pom;

    return max;
}

int main()
{
    int z, n, x;
    int* tab;

    cin >> z;

    int* pom = new int[z];

    if (z >= 1 && z <= 25) {
        for (int k = 0; k < z; k++) {
            cin >> n;

            if (n <= 200000) {
                tab = new int[n];

                for (int j = 0; j < n; j++) {
                    cin >> x;

                    if (x < 1000000000)
                        tab[j] = x;
                }

                pom[k] = Ciag_Licz(tab, n);

                delete[]tab;
            }
        }

        cout << endl;

        for (int i = 0; i < z; i++)
            cout << pom[i] << endl;
    }

    delete[] pom;

    return 0;
}
