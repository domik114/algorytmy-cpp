#include <iostream>
#include <chrono>

using namespace std;

void funkcja(int a)
{
    if (a == 0)
    {
        cout << "" << endl;
    }
    else
    {
        int suma = 0;

        for (int j = 1; j < a; j++)
            if (a % j == 0)
                suma += j;
        if (suma == a)
            cout << "TAK" << endl;
        else
            cout << "NIE" << endl;
    }
    

}

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    int x, i = 0;
    int tab[100];

    cout << "Dla danych:";

    do
    {
        cin >> x;
        if (x < 1000000000)
        {
            tab[i] = x;
            i++;
        }
    } while (x != 0);

    cout << endl << "poprawny wynik ma postac:" << endl;

    for (int j = 0; j < i; j++)
    {
        funkcja(tab[j]);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> czasobliczen = end - start;
    cout << "Czas obliczen: " << czasobliczen.count() << "sek\n";
}
