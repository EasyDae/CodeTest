//https://www.acmicpc.net/problem/14650

#include <iostream>

using namespace std;

int n;
int dp[10][3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    dp[1][0] = 0;
    dp[1][1] = 1;
    dp[1][2] = 1;
    cin >> n;

    for (int i = 2; i <= n; ++i)
        for (int j = 0; j < 3; ++j)
            dp[i][j] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];

    cout << dp[n][0];
}
