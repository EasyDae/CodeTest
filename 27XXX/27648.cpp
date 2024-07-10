//https://www.acmicpc.net/problem/27648

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k; cin >> n >> m >> k;
    if (k >= n + m - 1)
    {
        cout << "YES" << '\n';
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                int num = i + j + 1 <= k ? i + j + 1 : k;
                cout << num << ' ';
            }
            cout << '\n';
        }
    }
    else
        cout << "NO";
}
