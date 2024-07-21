//https://www.acmicpc.net/problem/2780

#include <iostream>

using namespace std;

int dp[1001][10];
int mod = 1234567;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 10; ++i)
        dp[1][i] = 1;

    for (int i = 2; i <= 1000; ++i)
    {
        dp[i][1] = (dp[i - 1][2] + dp[i - 1][4]) % mod;
        dp[i][2] = (dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][5]) % mod;
        dp[i][3] = (dp[i - 1][2] + dp[i - 1][6]) % mod;
        dp[i][4] = (dp[i - 1][1] + dp[i - 1][5] + dp[i - 1][7]) % mod;
        dp[i][5] = (dp[i - 1][2] + dp[i - 1][4] + dp[i - 1][6] + dp[i - 1][8]) % mod;
        dp[i][6] = (dp[i - 1][3] + dp[i - 1][5] + dp[i - 1][9]) % mod;
        dp[i][7] = (dp[i - 1][4] + dp[i - 1][8] + dp[i - 1][0]) % mod;
        dp[i][8] = (dp[i - 1][5] + dp[i - 1][7] + dp[i - 1][9]) % mod;
        dp[i][9] = (dp[i - 1][6] + dp[i - 1][8]) % mod;
        dp[i][0] = (dp[i - 1][7]) % mod;
    }

    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        long long ans = 0;
        for (int i = 0; i < 10; ++i)
            ans += dp[n][i] % mod;

        cout << ans % mod << '\n';
    }
}
