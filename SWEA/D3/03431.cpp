#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int a, b, c; cin >> a >> b >> c;

        cout << '#' << t << ' ';
        if (c > b)
            cout << -1 << '\n';
        else if (a <= c && c <= b)
            cout << 0 << '\n';
        else
            cout << a - c << '\n';
    }
}
