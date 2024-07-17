#include <iostream>
#include <chrono>

using namespace std;

void liczbaMnozen(int a) 
{
    int wynik = 0;
    for (int i=a; i>=0; i--)
    {
        wynik += i;
    }

    cout << wynik << endl;
}

float wielomian(int n, float x, float a[])
{
    float wynik = a[0];

    for (int i = 1; i <= n; i++)
        wynik = wynik * x + a[i];

    return wynik;
}

float wielomian2(int n, float x, float a[])
{
    float wynik = 0.0;
    if (n == 0)
        return a[0];

    return x * wielomian(n - 1, x, a) + a[n];
}

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    
    int n;
    float x;
    float *tab;

    cout << "Dla danych:" << endl;
    cin >> n >> x;

    tab = new float[n + 1];

    for (int i = n; i >= 0; i--)
        cin >> tab[i];

    cout << "Wersja 1: W(x): " << wielomian(n, x, tab) << ", liczba mnozen: "; liczbaMnozen(n);
    cout << "Wersja 2: W(x): " << wielomian2(n, x, tab) << ", liczba mnozen: " << n << endl;

    delete[] tab;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> czasobliczen = end - start;
    cout << "Czas obliczen: " << czasobliczen.count() << "sek\n";

    return 0;
}
