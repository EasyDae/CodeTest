//https://www.acmicpc.net/problem/21735

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m;
int arr[1000001];

int DFS(int idx, int cnt, int size)
{
    if (cnt > m)
        return 0;

    if (cnt == m)
        return size;

    int ans = max(DFS(idx + 1, cnt + 1, size + arr[idx + 1]), DFS(idx + 2, cnt + 1, size / 2 + arr[idx + 2]));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];

    cout << DFS(0, 0, 1);
}
