//https://www.acmicpc.net/problem/9084

#include <iostream>

using namespace std;

int dp[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> vec(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> vec[i];

        int m; cin >> m;

        for (int i = 1; i <= m; ++i)
            dp[i] = 0;
        dp[0] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (j - vec[i] >= 0)
                    dp[j] += dp[j - vec[i]];

        cout << dp[m] << '\n';
    }
}
