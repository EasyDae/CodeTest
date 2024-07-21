//https://www.acmicpc.net/problem/13023

#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> vec;
vector<bool> visited;
bool flag = 0;

void DFS(int idx, int cnt, vector<bool>&vc)
{
    if (cnt == 5)
    {
        flag = 1;
        return;
    }

    for (int i = 0; i < vec[idx].size(); ++i)
    {
        int tmp = vec[idx][i];
        if (visited[tmp])
            continue;

        visited[tmp] = 1;
        DFS(tmp, cnt + 1, visited);
        visited[tmp] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    vec = vector<vector<int>>(n);
    visited = vector<bool>(n);

    while (m--)
    {
        int a, b; cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    for (int i = 0; i < n; ++i)
    {
        visited[i] = 1;
        DFS(i, 1, visited);
        visited[i] = 0;
        if (flag)
            break;
    }

    cout << flag;
}
