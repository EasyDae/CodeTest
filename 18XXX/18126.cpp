//https://www.acmicpc.net/problem/18126

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool visited[5001];
vector<vector<pair<int, long long>>> vec;
long long ans = 0;
int n;

void DFS(int num, long long dist)
{
    if (dist > ans)
        ans = dist;
    visited[num] = 1;

    for (int i = 0; i < vec[num].size(); ++i)
    {
        int next = vec[num][i].first;
        if (!visited[next])
        {
            visited[next] = 1;
            DFS(next, dist + vec[num][i].second);
            visited[next] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    vec = vector<vector<pair<int, long long>>>(n + 1);

    for (int i = 1; i < n; ++i)
    {
        int a, b;
        long long dist;
        cin >> a >> b >> dist;
        vec[a].push_back({ b,dist });
        vec[b].push_back({ a,dist });
    }

    DFS(1, 0);
    cout << ans;
}
