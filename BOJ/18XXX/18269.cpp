//https://www.acmicpc.net/problem/18269

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    string s; cin >> s;

    for (int i = 1; i <= n; ++i)
    {
        bool flag = 1;
        for (int j = 0; j <= n - i; ++j)
        {
            string ss = s.substr(j, i);
            for (int k = 0; k <= n - i; ++k)
            {
                if (j == k)
                    continue;
                if (ss == s.substr(k, i))
                    flag = 0;
            }
        }
        if (flag)
        {
            cout << i;
            return 0;
        }
    }
}
