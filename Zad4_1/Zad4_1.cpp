#include <iostream>

using namespace std;

int ink = 0;

void printTab(int* tab, int n) {
	cout << endl;
	for (int x = 0; x < n; x++) {
		cout << tab[x] << " ";
	}
	cout << endl;
}

void Scalanie(int* tab, int lewy, int m, int prawy)
{
	int lSize = m - lewy + 1;
	int rSize = prawy - m;

	int* tabL = new int[lSize];
	int* tabR = new int[rSize];

	for (int x = 0; x < lSize; x++)
		tabL[x] = tab[lewy + x];
	for (int y = 0; y < rSize; y++)
		tabR[y] = tab[m + 1 + y];

	int indexL = 0;
	int indexR = 0;
	int currIndex;

	for (currIndex = lewy; indexL < lSize && indexR < rSize; currIndex++)
	{
		if (tabL[indexL] <= tabR[indexR])
			tab[currIndex] = tabL[indexL++];
		else
			tab[currIndex] = tabR[indexR++];
	}

	while (indexL < lSize)
		tab[currIndex++] = tabL[indexL++];

	while (indexR < rSize)
		tab[currIndex++] = tabR[indexR++];

	delete[] tabL;
	delete[] tabR;
}


void ScalanieSort(int* tab, int lewy, int prawy) {
	ink++;
	if (prawy > lewy) {
		int m = (lewy + prawy) / 2;
		ScalanieSort(tab, lewy, m);
		ScalanieSort(tab, m + 1, prawy);
		Scalanie(tab, lewy, m, prawy);
	}
}


int main()
{
	int n;
	int b;

	cin >> b;	
	
	for (int z = 0; z < b; z++) {
		cin >> n;
		int* tab = new int[n];
		for (int x = 0; x < n; x++) {
			cin >> tab[x];
		}
		ScalanieSort(tab, 0, n - 1);
		cout << "licznik = " << ink << endl;
		printTab(tab, n);
		cout << endl;
		delete[] tab;
		ink = 0;
	}

	return 0;
}