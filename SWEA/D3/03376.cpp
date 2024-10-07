#include<iostream>
 
using namespace std;
long long dp[101];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= 100; ++i)
        dp[i] = dp[i - 2] + dp[i - 3];
 
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n; cin >> n;
        cout << '#' << t << ' ' << dp[n] << '\n';
    }
}
