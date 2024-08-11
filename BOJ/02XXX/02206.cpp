//https://www.acmicpc.net/problem/2206

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n, m;
string arr[1001];
int visited[1001][1001][2];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int BFS() {
    queue<pair<int, pair<int, int>>> q;
    q.push({ 0, {0, 0} });
    visited[0][0][0] = 1;

    while (!q.empty()) {
        int wall = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        if (x == n - 1 && y == m - 1)
            return visited[x][y][wall];

        for (int i = 0; i < 4; ++i) {
            int ax = x + dx[i];
            int ay = y + dy[i];
            if (ax < 0 || ax >= n || ay < 0 || ay >= m)
                continue;

            if (arr[ax][ay] == '0' && visited[ax][ay][wall] == 0) {
                visited[ax][ay][wall] = visited[x][y][wall] + 1;
                q.push({ wall, {ax,ay} });
            }

            if (arr[ax][ay] == '1' && wall == 0) {
                visited[ax][ay][wall + 1] = visited[x][y][wall] + 1;
                q.push({ wall + 1, {ax,ay} });
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << BFS();
}
