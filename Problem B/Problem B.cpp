#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 

using namespace std;

/* lis() returns the length of the longest increasing
  subsequence in arr[] of size n */
int lis(int *arr, int n)
{
    int* lis, i, j, max = 0;
    lis = (int*)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
        lis[i] = 1;

    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;

    for (i = 0; i < n; i++)
        if (max < lis[i])
            max = lis[i];

    free(lis);

    return max;
}

int main()
{
    int z, n, x;
    int *tab = new int[];

    cin >> z;

    if (z >= 1 && z <= 25) {
        for (int k = 0; k < z; k++) {
            cin >> n;            

            if (n <= 200000) {
                tab = new int[n];

                for (int j = 0; j < n; j++) {
                    cin >> x;

                    if (x < 1000000000)
                        for (int i = 0; i < n; i++)
                            tab[i] = x;
                }
                
                printf("%d\n", lis(tab, n));

                delete[]tab;
            }
        }
    }    

    //int arr[] = { 5, 3, 4, 9, 2, 8, 6, 7, 1 };
    //int n = sizeof(arr) / sizeof(arr[0]);
    //printf("%d\n", lis(arr, n));

    return 0;
}
