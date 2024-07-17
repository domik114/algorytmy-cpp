#include<iostream>

using namespace std;

void sortowanie_przez_wstawianie(int n, int* tab)
{
    int pom, j;
    for (int i = 1; i < n; i++)
    {
        pom = tab[i];
        j = i - 1;

        while (j >= 0 && tab[j] > pom)
        {
            tab[j + 1] = tab[j]; 
            --j;
        }
        tab[j + 1] = pom; 
    }
}

int main()
{
    int n, * tab;
    int z;
    cin >> z;
    
    if (z >= 1 && z <= 20) {
        for (int k = 0; k < z; k++) {
            cin >> n;

            if (n >= 2 && n <= 1000) {
                tab = new int[n];

                for (int i = 0; i < n; i++)
                    cin >> tab[i];

                cout << endl;

                sortowanie_przez_wstawianie(n, tab);

                for (int i = 0; i < n; i++)
                    cout << tab[i] << " ";
                cout << endl;
            }            
        }
    }   

    cin.ignore();
    cin.get();
    return 0;
}