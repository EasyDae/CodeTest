//https://www.acmicpc.net/problem/1753

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int v, e, k;
vector<vector<pair<int, int>>> vec;
int arr[20001];

void BFS()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, k });
    arr[k] = 0;

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist > arr[cur]) continue;

        for (int i = 0; i < vec[cur].size(); ++i)
        {
            int next = vec[cur][i].first;
            int ndist = vec[cur][i].second;

            if (arr[next] > dist + ndist)
            {
                arr[next] = dist + ndist;
                pq.push({ arr[next], next });
            }
        }
    }

    for (int i = 1; i <= v; ++i)
    {
        if (arr[i] == 2147483647)
            cout << "INF" << '\n';
        else
            cout << arr[i] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> v >> e >> k;
    vec = vector<vector<pair<int, int>>>(v + 1);
    for (int i = 0; i < e; ++i)
    {
        int a, b, dist;
        cin >> a >> b >> dist;
        vec[a].push_back({ b,dist });
    }

    for (int i = 1; i <= v; ++i)
        arr[i] = 2147483647;

    BFS();
}
