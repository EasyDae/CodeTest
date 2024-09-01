#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        string s; cin >> s;
        if ((s[s.size() - 1] - '0') % 2)
            cout << '#' << t << ' ' << "Odd" << '\n';
        else
            cout << '#' << t << ' ' << "Even" << '\n';
    }
}
