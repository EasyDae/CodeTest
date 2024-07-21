//https://www.acmicpc.net/problem/1914

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void hanoi(int n, int start, int mid, int end)
{
    if (n == 1)
    {
        cout << start << ' ' << end << '\n';
        return;
    }

    hanoi(n - 1, start, end, mid);
    cout << start << ' ' << end << '\n';
    hanoi(n - 1, mid, start, end);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    string s = to_string(pow(2, n));
    int x = s.find(".");
    s = s.substr(0, x);
    s[s.size() - 1] -= 1;
    cout << s << '\n';

    if (n <= 20)
        hanoi(n, 1, 2, 3);

    return 0;
}
