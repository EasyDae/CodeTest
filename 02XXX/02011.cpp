//https://www.acmicpc.net/problem/2011

#include <iostream>

using namespace std;

int arr[5001], dp[5001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int mod = 1000000, len;
    string s; cin >> s;
    len = s.size();

    for (int i = 1; i <= len; ++i)
        arr[i] = s[i - 1] - '0';

    if (len == 1 && s[0] == '0')
    {
        cout << 0;
        return 0;
    }

    dp[0] = 1;
    for (int i = 1; i <= len; ++i)
    {
        if (arr[i] > 0 && arr[i] < 10)
            dp[i] = (dp[i - 1] + dp[i]) % mod;

        if (i == 1)
            continue;

        int tmp = arr[i - 1] * 10 + arr[i];
        if (tmp > 9 && tmp < 27)
            dp[i] = (dp[i - 2] + dp[i]) % mod;
    }

    cout << dp[len];
}
