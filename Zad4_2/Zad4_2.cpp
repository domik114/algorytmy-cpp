#include <iostream>

using namespace std;

int ink = 0;

void printTab(int* tab, int n) {
    cout << endl;
    for (int x = 0; x < n; x++) {
        cout << tab[x] << " ";
    }
    cout << endl;
}

void QuickSort(int* tablica, int lewy, int prawy)
{
    ink++;
    int v = tablica[(lewy + prawy) / 2];
    int i, j, x;
    i = lewy;
    j = prawy;
    do
    {
        while (tablica[i] < v) i++;
        while (tablica[j] > v) j--;
        if (i <= j)
        {
            x = tablica[i];
            tablica[i] = tablica[j];
            tablica[j] = x;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > lewy) QuickSort(tablica, lewy, j);
    if (i < prawy) QuickSort(tablica, i, prawy);
}

int main()
{
    int n;
    int b;
    int s = 0;

    cin >> b;

    for (int z = 0; z < b; z++) {
        cin >> n;
        int* tab = new int[n];
        for (int x = 0; x < n; x++) {
            cin >> tab[x];
        }
        QuickSort(tab, 0, n - 1);
        cout << "licznik = " << ink << endl;
        printTab(tab, n);
        cout << endl;
        delete[] tab;
        ink = 0;
    }

    return 0;
}