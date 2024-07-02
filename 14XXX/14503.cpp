//https://www.acmicpc.net/problem/14503

#include <iostream>
#include <queue>

using namespace std;

int n, m, r, c, dir, cnt;
bool arr[51][51], visited[51][51];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void BFS()
{
    queue<pair<int, int>> q;
    q.push({ r,c });
    
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (!visited[x][y])
        {
            visited[x][y] = 1;
            cnt++;
        }

        bool flag = 0;
        for (int i = 0; i < 4; ++i)
        {
            dir = (dir + 3) % 4;
            int ax = x + dx[dir];
            int ay = y + dy[dir];

            if (!arr[ax][ay] && !visited[ax][ay])
            {
                q.push({ ax,ay });
                flag = 1;
                break;
            }
        }

        if (!flag)
        {
            int ax = x + dx[(dir + 2) % 4];
            int ay = y + dy[(dir + 2) % 4];

            if (arr[ax][ay])
                return;
            else
                q.push({ ax,ay });
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> r >> c >> dir;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> arr[i][j];

    BFS();
    cout << cnt << '\n';
}
