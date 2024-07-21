//https://www.acmicpc.net/problem/1679

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, Max = 0;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> vec[i];
        Max = max(Max, vec[i]);
    }

    cin >> k;

    Max = Max * k + 2;
    vector<int> dp(Max, 2147483647);

    for (int i = 0; i < n; ++i)
        dp[vec[i]] = 1;

    for (int i = 1; i < Max; ++i) 
    {
        for (int j = 1; j <= i / 2; ++j)
            dp[i] = min(dp[i], dp[j] + dp[i - j]);

        if (dp[i] > k) 
        {
            string s = (i % 2 == 0) ? "holsoon" : "jjaksoon";
            cout << s << " win at " << i << '\n';
            break;
        }
    }
}
