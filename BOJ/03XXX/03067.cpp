//https://www.acmicpc.net/problem/3067

#include <iostream>

using namespace std;

int dp[10001];
int arr[20];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        int m; cin >> m;
        for (int i = 1; i <= m; ++i)
            dp[i] = 0;
        dp[0] = 1;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (j - arr[i] >= 0)
                    dp[j] += dp[j - arr[i]];
            }
        }

        cout << dp[m] << '\n';
    }
}
