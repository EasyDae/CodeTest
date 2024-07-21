//https://www.acmicpc.net/problem/15486

#include <iostream>
#include <vector>

using namespace std;

int n;
int dp[1500001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    vector<pair<int, int>> pr(n + 1);

    for (int i = 0; i < n; ++i)
        cin >> pr[i].first >> pr[i].second;

    int Max = 0;
    for (int i = 0; i <= n; ++i)
    {
        Max = max(Max, dp[i]);
        if (i + pr[i].first > n)
            continue;

        dp[i + pr[i].first] = max(dp[i + pr[i].first], Max + pr[i].second);
    }

    cout << Max;
}
