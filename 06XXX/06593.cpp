//https://www.acmicpc.net/problem/6593

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int L, R, C;
int visited[31][31][31];
char arr[31][31][31];
int dx[] = { 0,0,1,-1,0,0 };
int dy[] = { 1,-1,0,0,0,0 };
int dz[] = { 0,0,0,0,1,-1 };

void BFS(int a, int b, int c)
{
    queue<pair<int, pair<int, int>>> q;
    q.push({ a,{b,c} });

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second.first;
        int z = q.front().second.second;
        q.pop();

        for (int i = 0; i < 6; ++i)
        {
            int ax = x + dx[i];
            int ay = y + dy[i];
            int az = z + dz[i];

            if (ax < 0 || ax >= R || ay < 0 || ay >= C || az < 0 || az >= L || arr[ax][ay][az] == '#' || visited[ax][ay][az])
                continue;

            visited[ax][ay][az] = visited[x][y][z] + 1;
            q.push({ ax,{ay,az} });
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1){
        cin >> L >> R >> C;
        if (L == 0)
            break;

        memset(visited, 0, sizeof(visited));

        int x1, y1, z1, x2, y2, z2;

        for (int k = 0; k < L; ++k){
            for (int i = 0; i < R; ++i) {
                for (int j = 0; j < C; ++j) {
                    cin >> arr[i][j][k];

                    if (arr[i][j][k] == 'S')
                        tie(x1, y1, z1) = tie(i, j, k);

                    if(arr[i][j][k] == 'E')
                        tie(x2, y2, z2) = tie(i, j, k);
                }
            }
        }

        BFS(x1, y1, z1);

        if (!visited[x2][y2][z2])
            cout << "Trapped!\n";
        else
            cout << "Escaped in " << visited[x2][y2][z2] << " minute(s).\n";
    }
}
