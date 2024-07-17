﻿#include <iostream>
#include <string>

using namespace std;

int main()
{
    int z;
    cin >> z;

    for (int k = 0; k < z; k++)
    {
        string s1, s2, sLCS;
        int** L, i, j, m, n;

        cin >> s1;
        cin >> s2;

        m = s1.length();
        n = s2.length();

        L = new int* [m + 1];
        for (i = 0; i <= m; i++)
            L[i] = new int[n + 1];

        for (i = 0; i <= m; i++)
            L[i][0] = 0;
        for (j = 0; j <= n; j++)
            L[0][j] = 0;
        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                if (s1[i] == s2[j])
                    L[i + 1][j + 1] = 1 + L[i][j];
                else
                    L[i + 1][j + 1] = max(L[i + 1][j], L[i][j + 1]);

        sLCS = ""; i = m - 1; j = n - 1;
        while ((i >= 0) && (j >= 0))
            if (s1[i] == s2[j])
            {
                sLCS = s1[i] + sLCS;
                i--; j--;
            }
            else if (L[i + 1][j] > L[i][j + 1]) j--;
            else i--;
        cout <<"Wynik: " <<  sLCS << endl;
        cout << endl;

    }
    return 0;
}