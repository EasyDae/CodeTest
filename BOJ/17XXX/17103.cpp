//https://www.acmicpc.net/problem/17103

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int prime[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 2; i <= 1000000; i++)
        if (!prime[i])
            for (int j = 2 * i; j <= 1000000; j += i)
                prime[j] = 1;

    int t; cin >> t;
    while (t--)
    {
        int n, cnt = 0; cin >> n;
        for (int i = 2; i <= n / 2; ++i)
        {
            int a = i;
            int b = n - i;

            if (!prime[a] && !prime[b])
                cnt++;
        }

        cout << cnt << '\n';
    }
}
