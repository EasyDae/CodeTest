#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string.h>

using namespace std;

int n;
int arr[101][101], map[101][101];
bool visited[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void BFS() {
    queue<pair<int, int>> q;
    q.push({ 0,0 });

    visited[0][0] = 1;
    map[0][0] = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int ax = x + dx[i];
            int ay = y + dy[i];

            if (ax < 0 || ax >= n || ay < 0 || ay >= n)
                continue;

            if (!visited[ax][ay] || map[ax][ay] > map[x][y] + arr[ax][ay]) {
                visited[ax][ay] = 1;
                map[ax][ay] = map[x][y] + arr[ax][ay];
                q.push({ ax,ay });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    for (int i = 1; i <= t; ++i) {
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));
        
        cin >> n;
        for (int i = 0; i < n; ++i){
            string s; cin >> s;
            for (int j = 0; j < n; ++j)
                arr[i][j] = s[j]-'0';
        }

        BFS();

        cout << '#' << i << ' ' << map[n - 1][n - 1] << '\n';
    }
}
