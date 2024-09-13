#include<iostream>

using namespace std;

long long dp[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 1; i <= 1000000; i += 2)
        for (int j = i; j <= 1000000; j += i)
            dp[j] += i;

    for (int i = 2; i <= 1000000; ++i)
        dp[i] += dp[i - 1];

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int l, r; cin >> l >> r;
        cout << '#' << t << ' ' << dp[r] - dp[l - 1] << '\n';
    }
}
