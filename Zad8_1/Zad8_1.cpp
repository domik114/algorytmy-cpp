#include<iostream>

using namespace std;

struct date {
    int day;
    int month;
    int year;
    int valid = 1;
};

int datevalidate(int dd, int mm, int yy) {
    if (yy >= 2000 && yy <= 2020) {
        if (mm >= 1 && mm <= 12) {
            if ((dd >= 1 && dd <= 31) && (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12));
            else if ((dd >= 1 && dd <= 30) && (mm == 4 || mm == 6 || mm == 9 || mm == 11));
            else if ((dd >= 1 && dd <= 28) && (mm == 2));
            else if (dd == 29 && mm == 2 && (yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0)));
            else
                return 0;
        }
        else 
            return 0;
    }
    else 
        return 0;
}

int main() {
    int z;
    int n;

    cin >> z;
    for (int x = 0; x < z; x++)
    {
        cin >> n;
            struct date input[24];
            for (int i = 0; i < n; i++) {
                cin >> input[i].year;
                cin >> input[i].month;
                cin >> input[i].day;
                input[i].valid = datevalidate(input[i].year, input[i].month, input[i].day);
                if (input[i].valid) {
                    cout << "Date is invalid";
                    exit(0);
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (input[i].year > input[j].year) {
                        struct date temp = input[i];
                        input[i] = input[j];
                        input[j] = temp;
                    }
                    else if (input[i].year == input[j].year && input[i].month < input[j].month) {
                        struct date temp = input[i];
                        input[i] = input[j];
                        input[j] = temp;
                    }
                    else if (input[i].year == input[j].year && input[i].month == input[j].month && input[i].day < input[j].day) {
                        struct date temp = input[i];
                        input[i] = input[j];
                        input[j] = temp;
                    }
                }
            }

            cout << endl;

            cout << "Numer testu " << x+1 << endl;
            for (int i = 0; i < n; i++) {
                cout << input[i].year << "" << input[i].month << "" << input[i].day;
                cout << endl;
            }
            cout << endl;
    }
}
