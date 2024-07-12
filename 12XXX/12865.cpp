//https://www.acmicpc.net/problem/12865

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int dp[101][100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k; cin >> n >> k;
    vector<pair<int, int>> vec(n + 1);

    for (int i = 1; i <= n; ++i)
        cin >> vec[i].first >> vec[i].second;

    for (int i = 0; i <= n; ++i)
        dp[i][0] = 0;
    for (int i = 0; i <= k; ++i)
        dp[0][k] = 0;

    for (int i = 1; i <= k; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (vec[j].first > i)
                dp[j][i] = dp[j - 1][i];
            else
                dp[j][i] = max(dp[j - 1][i - vec[j].first] + vec[j].second, dp[j - 1][i]);
        }
    }

    cout << dp[n][k];
}
