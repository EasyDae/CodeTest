#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int cnt = 0;
        string s; cin >> s;

        int prev = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] - '0' != prev) {
                prev = (prev + 1) % 2;
                cnt++;
            }
        }
        cout << '#' << t << ' ' << cnt << '\n';
    }
}
