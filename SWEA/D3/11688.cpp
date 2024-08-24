#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        string s; cin >> s;
        int a = 1, b = 1;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'L')
                b = a + b;
            else
                a = a + b;
        }

        cout << '#' << t << ' ' << a << ' ' << b << '\n';
    }
}
