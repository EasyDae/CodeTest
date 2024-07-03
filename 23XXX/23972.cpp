//https://www.acmicpc.net/problem/23972

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long k, n; cin >> k >> n;
    if (n == 1)
        cout << -1;
    else
    {
        long long tmp = (k * n) / (n - 1);
        if ((k * n) % (n - 1))
            tmp++;
        cout << tmp;
    }
}
