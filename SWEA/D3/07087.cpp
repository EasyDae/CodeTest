#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n; cin >> n;
        int arr[26] = { 0, };
        for (int i = 0; i < n; ++i) {
            string s; cin >> s;
            arr[s[0] - 'A']++;
        }

        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            if (!arr[i])
                break;
            ans++;
        }

        cout << '#' << t << ' ' << ans << '\n';
    }
}
