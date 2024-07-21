//https://www.acmicpc.net/problem/1011

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--)
    {
        long long x, y; cin >> x >> y;
        long long dist = y - x;

        double db = sqrt(dist);
        int tmp = round(db);

        if (db <= tmp)
            cout << 2 * tmp - 1 << '\n';
        else
            cout << 2 * tmp << '\n';
    }
}
