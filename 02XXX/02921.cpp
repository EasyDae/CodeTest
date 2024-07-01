//https://www.acmicpc.net/problem/2921

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, cnt = 0; cin >> n;

    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= i; ++j)
            cnt += i + j;

    cout << cnt;
}
