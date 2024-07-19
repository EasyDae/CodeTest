//https://www.acmicpc.net/problem/14381

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    for(int j=1; j<=t; ++j)
    {
        int n, ans = 0; cin >> n;
        bool check[10] = { 0, };

        for (int i = 1; i <= 100; ++i)
        {
            int tmp = n * i;
            string s = to_string(tmp);
            for (auto& x : s)
                check[x - '0'] = 1;

            bool flag = 0;
            for (int i = 0; i < 10; ++i)
                if (!check[i])
                    flag = 1;

            if (!flag)
            {
                ans = tmp;
                break;
            }
        }

        cout << "Case #" << j << ": ";

        if (!ans)
            cout << "INSOMNIA" << '\n';
        else
            cout << ans << '\n';
    }
}
