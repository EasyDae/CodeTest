#include<iostream>
#include<queue>
#include<string.h>

using namespace std;

int sx, sy, ex, ey;
string arr[101];
bool visited[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void BFS() {
    queue<pair<int, int>> q;
    q.push({ sx,sy });

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int ax = x + dx[i];
            int ay = y + dy[i];

            if (ax < 0 || ax >= 100 || ay < 0 || ay >= 100 || visited[ax][ay] || arr[ax][ay] == '1')
                continue;

            visited[ax][ay] = 1;
            q.push({ ax,ay });
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int test_case = 1; test_case <= 10; ++test_case)
    {
        memset(visited, 0, sizeof(visited));
        
        int t; cin >> t;
        for (int i = 0; i < 100; ++i){
            cin >> arr[i];
            for(int j=0; j<100; ++j){
                if(arr[i][j] == '2')
                    sx = i, sy = j;
                if(arr[i][j] == '3')
                    ex = i, ey = j;
            }
        }

        BFS();
        cout << '#' << test_case << ' ' << visited[ex][ey] << '\n';
    }
    return 0;
}
