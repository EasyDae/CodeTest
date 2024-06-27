//https://www.acmicpc.net/problem/2553

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    long long num = 1;
    for (int i = 1; i <= n; ++i)
    {
        num *= i;
        num %= 10000000;
        while (num % 10 == 0)
            num /= 10;
    }

    cout << num % 10;
}
