#include <iostream>
#include <chrono>

using namespace std;

int fun1(int a, int b)
{
    if (b < 0) b = b * (-1);
    while (a != b) 
    {
        if (a > b)
        {
            a -= b;
        }
        else
        {
            b -= a;
        }
    }
    
    return a;
}

int fun2(int a, int b)
{
    int reszta;

    while (b)
    {
        reszta = a % b;
        a = b;
        b = reszta;
    }

    return a;
}


int fun3(int a, int b)
{
    if (b==0) 
    {
        return a;
    }
    else
    {
        return fun3(b, a % b);
    }
}

int main()
{
    int a, b;
    cout << "Podaj a oraz potege b" << endl;
    cin >> a;
    cin >> b;

    auto start1 = std::chrono::steady_clock::now();
    cout << "NWD1(" << a << ", " << b << ") = " << fun1(a, b);
    auto end1 = std::chrono::steady_clock::now();
    std::chrono::duration<double> czasobliczen1 = end1 - start1;
    cout << " Czas Obliczen: " << czasobliczen1.count() << " sek" << endl;

    auto start2 = std::chrono::steady_clock::now();
    cout << "NWD2("<< a << ", " << b << ") = " << fun2(a, b);
    auto end2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> czasobliczen2 = end2 - start2;
    cout << " Czas Obliczen: " << czasobliczen2.count() << " sek" << endl;

    auto start = std::chrono::steady_clock::now();
    cout << "NWD3("<< a << ", " << b << ") = " << fun3(a, b);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> czasobliczen = end - start;
    cout << " Czas Obliczen: " << czasobliczen.count() << " sek" << endl;

    system("pause");
}