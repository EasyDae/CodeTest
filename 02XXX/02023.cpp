https://www.acmicpc.net/problem/2023

#include <iostream>

using namespace std;

int n;

bool isprime(int num)
{
    for (int i = 2; i * i <= num; ++i)
        if (num % i == 0)
            return 0;
    return 1;
}

void DFS(int num, int len)
{
    if (len == n)
    {
        cout << num << '\n';
        return;
    }

    for (int i = 1; i < 10; ++i)
        if (isprime(num * 10 + i))
            DFS(num * 10 + i, len + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    DFS(2, 1);
    DFS(3, 1);
    DFS(5, 1);
    DFS(7, 1);
}
