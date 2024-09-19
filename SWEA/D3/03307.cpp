#include<iostream>
#include<vector>

using namespace std;

int dp[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n; cin >> n;
        vector<int> vec(n);
        for (int i = 0; i < n; ++i)
            cin >> vec[i];

        dp[0] = 1;
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (vec[j] < vec[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(ans, dp[i]);
                }
            }
        }

        cout << '#' << t << ' ' << ans << '\n';
    }
}
