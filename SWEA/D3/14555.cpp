#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        string s; cin >> s;
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                ans++;
            if (s[i] == ')')
                if (s[i - 1] != '(')
                    ans++;
        }

        cout << '#' << t << ' ' << ans << '\n';
    }
}