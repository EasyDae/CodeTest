//https://www.acmicpc.net/problem/28065

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    int num = 1;
    for (int i = 1; i <= n; ++i)
    {
        cout << num << ' ';
        if (i % 2)
            num += n - i;
        else
            num -= n - i;
    }
}
