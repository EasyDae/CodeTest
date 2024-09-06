#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        string s; cin >> s;
        int cnt = 0;
        for (auto& x : s)
            if (x == 'x')
                cnt++;

        if (cnt >= 8) cout << '#' << t << ' ' << "NO\n";
        else cout << '#' << t << ' ' << "YES\n";
    }
}
