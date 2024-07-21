//https://www.acmicpc.net/problem/6463

#include <iostream>
#include <iomanip>

using namespace std;

int fact(int n)
{
    long long ll = 1;
    for (int i = 1; i <= n; ++i)
    {
        ll = (ll * i) % 10000000;
        while (ll % 10 == 0)
            ll /= 10;
    }

    return ll % 10;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    while(cin >> n)
    {
        cout << right;
        cout << setw(5) << n << " -> " << fact(n) << '\n';
    }
}
