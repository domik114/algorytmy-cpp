#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void sortowanie_przez_zliczanie(int* lista, int zakres_od, int zakres_do, int n) {
    int dl = zakres_do - zakres_od + 1;
    int* zlicz = new int[dl];
    for (int i = 0; i < dl; i++)
        zlicz[i] = 0;
    for (int i = 0; i < n; i++)
        zlicz[lista[i] - zakres_od]++;
    int x = 0;
    for (int i = 0; i < dl; i++)
        for (int j = 0; j < zlicz[i]; j++)
            lista[x++] = i + zakres_od;
}

int main()
{
    int z, n, zakres_od, zakres_do;
    zakres_od = 0;
    zakres_do = 100;
    cin >> z;
    if (z >= 1 && z <= 20) {
        for (int k = 0; k < z; k++) {
            cin >> n;

            if (n >= 2 && n <= 1000) {
                int* L = new int[n];

                for (int i = 0; i < n; i++)
                    cin >> L[i];

                cout << endl;

                sortowanie_przez_zliczanie(L, zakres_od, zakres_do, n);

                for (int i = 0; i < n; i++)
                    cout << L[i] << " ";
                cout << endl;

                delete[] L;
            }            
        }        
    }

    return 0;
}