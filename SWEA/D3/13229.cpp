#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << '#' << i << ' ';

        string day; cin >> day;
        if (day == "MON")
            cout << 6;
        else if (day == "TUE")
            cout << 5;
        else if (day == "WED")
            cout << 4;
        else if (day == "THU")
            cout << 3;
        else if (day == "FRI")
            cout << 2;
        else if (day == "SAT")
            cout << 1;
        else
            cout << 7;

        cout << '\n';
    }
}
