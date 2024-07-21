//https://www.acmicpc.net/problem/18222

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long func(long long a)
{
    if (a == 1)
        return 0;

    long long i;
    for (i = 1; i + i < a; i += i);
    return !func(a - i);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long k; cin >> k;

    cout << func(k);
}
