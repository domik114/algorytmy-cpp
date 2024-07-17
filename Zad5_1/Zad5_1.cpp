#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

void kadanes(int a[], int size)
{
    int max_so_far = INT_MIN; int max_ending_here = 0,
        start = 0, end = 0, s = 0;

    for (int i = 0; i < size; i++)
    {
        max_ending_here += a[i];

        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }

        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i + 1;
        }
    }
    cout << max_so_far << " " << start + 1 << " " << end + 1 << endl;
}

int main()
{
    int z;
    cin >> z;
    int tab[100][1000];
    int tab2[1000];
    int n[100];
    int nn;
    
    for (int i = 0; i < z; i++)
    {
        cin >> n[i];
        for (int i2 = 0; i2 < n[i]; i2++)
            cin >> tab[i][i2];
    }
    cout << endl;
    for (int ii = 0; ii < z; ii++)
    {
        for (int iii = 0; iii < n[ii]; iii++)
        {
            nn = n[ii];
            tab2[iii] = tab[ii][iii];
        }
        kadanes(tab2, nn);
    }

}
