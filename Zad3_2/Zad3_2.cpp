#include <iostream>
#include <string>

using namespace std;

int main()
{
    string n;
    int a;
    int i = 0;
    string tab[20];

    do {
        do {
            cin >> n;
            a = stoi(n);
            if (a > 0 && a < 1000000000)
                tab[i] = n;
            i++;
        } while (a != 0);
        
    } while (a != 0);

    for (int k = 0; k < i-1; k++) {
        n = tab[k];
        cout << n << ": ";
        for (int i = n.length(); i >= 0; i--) {
             cout << n[i] << " ";
        }        
        cout << "# ";
        for (int i = 0; i <= n.length(); i++) {
            cout << n[i] << " ";
        }
        cout << endl;
    }

    return 0;
}