//https://www.acmicpc.net/problem/4811

#include <iostream>

using namespace std;

long long dp[31][31];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i <= 30; ++i)
    {
        for (int j = 0; j <= 30; ++j)
        {
            if (i > j)
                continue;

            if (i == 0)
                dp[j][i] = 1;
            else
                dp[j][i] = dp[j - 1][i] + dp[j][i - 1];
        }
    }

    while (1)
    {
        int n; cin >> n;
        if (n == 0)
            return 0;

        cout << dp[n][n] << '\n';
    }
}
