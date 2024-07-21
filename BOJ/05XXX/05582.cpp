https://www.acmicpc.net/problem/5582

#include <iostream>
#include <cmath>

using namespace std;

int dp[4001][4001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1, s2; cin >> s1 >> s2;
    int len1 = s1.size(), len2 = s2.size();
    int Max = 0;

    for (int i = 1; i <= len1; ++i)
    {
        for (int j = 1; j <= len2; ++j)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                Max = max(Max, dp[i][j]);
            }
        }
    }

    cout << Max;
}
