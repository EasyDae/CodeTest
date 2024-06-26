//https://www.acmicpc.net/problem/31134

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--)
    {
        long long x; cin >> x;
        cout << 2 * x - 1 << '\n';
    }
}
