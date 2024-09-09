#include<iostream>

using namespace std;

int month[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int m, d; cin >> m >> d;
        int sum = 0;
        for (int i = 0; i < m - 1; ++i)
            sum += month[i];
        sum += d + 3;
        cout << '#' << t << ' ' << sum % 7 << '\n';
    }
}
