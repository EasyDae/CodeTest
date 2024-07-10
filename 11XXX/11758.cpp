//https://www.acmicpc.net/problem/11758

#include <iostream>

using namespace std;

int CCW(int a1, int b1, int a2, int b2, int a3, int b3)
{
    return (a2 - a1) * (b3 - b1) - (a3 - a1) * (b2 - b1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int result = CCW(x1, y1, x2, y2, x3, y3);

    if (result == 0)
        cout << 0;
    else if (result < 0)
        cout << -1;
    else
        cout << 1;
}
