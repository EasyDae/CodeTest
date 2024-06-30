//https://www.acmicpc.net/problem/17536

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v, n; cin >> v >> n;

    for (int i = 1; i < 10; ++i)
    {
        if ((i * v * n) % 10)
            cout << (i * v * n) / 10 + 1 << ' ';
        else
            cout << (i * v * n) / 10 << ' ';
    }
}
