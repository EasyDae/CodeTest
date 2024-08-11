//https://www.acmicpc.net/problem/5972

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n, m;
vector<vector<pair<int, int>>> vec;
int dist[50001];

void DFS(int start) {
    for (int i = 1; i <= n; ++i)
        dist[i] = 99999999;
    priority_queue<pair<int, int>> pq;
    pq.push({ 0, start });
    dist[start] = 0;
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < vec[cur].size(); ++i) {
            int next = vec[cur][i].first;
            int nextcost = vec[cur][i].second + cost;
            if (dist[next] > nextcost) {
                dist[next] = nextcost;
                pq.push({ -dist[next], next });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    vec = vector<vector<pair<int, int>>>(n + 1);

    for (int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        vec[a].push_back({ b,c });
        vec[b].push_back({ a,c });
    }

    DFS(1);

    cout << dist[n];
}
