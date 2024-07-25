//https://www.acmicpc.net/problem/16195

#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

long long dp[1001][1001];
int mod = 1000000009;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 2;
    dp[3][3] = 1;

    for (int i = 4; i <= 1000; ++i)
        for (int j = 2; j <= i; ++j)
            dp[i][j] += (dp[i - 1][j - 1] + dp[i - 2][j - 1] + dp[i - 3][j - 1]) % mod;

    while (t--) {
        int n, m; cin >> n >> m;

        long long ans = 0;
        for (int i = 1; i <= m; ++i)
            ans = (ans + dp[n][i]) % mod;

        cout << ans << '\n';
    }
}
