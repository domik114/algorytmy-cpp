#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool czyPoprawne(string slowo, string arg = "{}()[]") {
    vector<char> lista;
    for (int i = 0; i < slowo.length(); i++) {
        int poz = arg.find(slowo[i]);
        if (poz == string::npos)
            continue;
        if (poz % 2 == 0) {
            lista.push_back(arg[poz + 1]);
        }
        else {
            if (lista.size() == 0 || lista.back() != slowo[i])
                return false;
            lista.pop_back();
        }
    }
    return lista.size() == 0;
}

int main() {
    int z;
    string s = "";

    string tab[100];
    bool tabB[100];

    cin >> z;

    for (int i = 0; i <= z; i++)
    {
        getline(cin, s);
        tab[i] = s;
    }

    cout << endl;

    for (int i = 0; i <= z; i++)
    {
        s = tab[i];
        bool w = true;
        w = czyPoprawne(s);

        if (i != z) {
            if (w == true)
                cout << "TAK" << endl;
            else
                cout << "NIE" << endl;
        }
    }


    return 0;
}