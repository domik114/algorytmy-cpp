#include <iostream>
#include <chrono>

using namespace std;

int fun1(int a, int b)
{
    int result = 1;
    for (int i = 0; i < b; i++)
    {
        result *= a;
    }
    return result;
}

int fun2(int a, int b)
{
    if (b == 0)
        return 1;
    else
        return  a * fun2(a, --b);

}


int fun3(int a, int b)
{
    if (b == 1)
        return a;
    if (b % 2 == 0)
    {
        int t = fun3(a, b / 2);
        return t * t;
    }
    else
    {
        int t = fun3(a, b - 1);
        return a * t;
    }
}

int main()
{
    int a, b;
    cout << "Podaj a oraz potege b" << endl;
    cin >> a;
    cin >> b;

    auto start1 = std::chrono::steady_clock::now();
    cout << fun1(a, b);
    auto end1 = std::chrono::steady_clock::now();
    std::chrono::duration<double> czasobliczen1 = end1 - start1;
    cout << " Czas Obliczen: " << czasobliczen1.count() << " sek" << endl;

    auto start2 = std::chrono::steady_clock::now();
    cout << fun2(a, b);
    auto end2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> czasobliczen2 = end2 - start2;
    cout << " Czas Obliczen: " << czasobliczen2.count() << " sek" << endl;

    auto start = std::chrono::steady_clock::now();
    cout << fun3(a, b);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> czasobliczen = end - start;
    cout << " Czas Obliczen: " << czasobliczen.count() << " sek" << endl;

    system("pause");
}