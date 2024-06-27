//https://www.acmicpc.net/problem/24481

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int n, m, r;
vector<vector<int>> vec;
int depth[100001];

void dfs(int a, int cnt)
{
    depth[a] = cnt;
    for (int i = 0; i < vec[a].size(); ++i)
    {
        int tmp = vec[a][i];
        if (depth[tmp] != -1)
            continue;

        dfs(tmp, cnt + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(depth, -1, sizeof(depth));

    cin >> n >> m >> r;
    vec = vector<vector<int>>(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    for (int i = 0; i < n; ++i)
        sort(vec[i].begin(), vec[i].end());

    dfs(r, 0);

    for (int i = 1; i <= n; ++i)
        cout << depth[i] << '\n';
}
