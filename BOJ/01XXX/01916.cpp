//https://www.acmicpc.net/problem/1916

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[1001];
int n, m, st, ed;
vector<vector<pair<int, int>>> vec(1001);

void func()
{
    priority_queue<pair<int, int>> pq;
    pq.push({ 0, st });
    arr[st] = 0;
    while (!pq.empty())
    {
        int cost = pq.top().first;
        int loc = pq.top().second;
        pq.pop();

        if (arr[loc] < cost)
            continue;

        for (int i = 0; i < vec[loc].size(); ++i)
        {
            int tmp = vec[loc][i].first;
            int fair = cost + vec[loc][i].second;
            if (arr[tmp] > fair)
            {
                arr[tmp] = fair;
                pq.push({ ncost, tmp });
            }
        }
    }
    cout << arr[ed];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int s, e, cost; cin >> s >> e >> cost;
        vec[s].push_back({e,cost});
    }

    cin >> st >> ed;

    for (int i = 1; i <= n; ++i)
        arr[i] = 2147483647;

    func();
}
