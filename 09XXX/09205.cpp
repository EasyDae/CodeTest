//https://www.acmicpc.net/problem/9205

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int n, hx, hy, dx, dy;
vector<pair<int, int>> vec;
bool visited[100];

bool BFS()
{
    queue<pair<int, int>> q;
    q.push({ hx,hy });

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (abs(dx - x) + abs(dy - y) <= 1000)
            return true;

        for (int i = 0; i < n; ++i)
        {
            if (visited[i])
                continue;

            if (abs(vec[i].first - x) + abs(vec[i].second - y) <= 1000)
            {
                visited[i] = 1;
                q.push({ vec[i].first, vec[i].second });
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--)
    {
        memset(visited, 0, sizeof(visited));

        cin >> n;
        vec = vector<pair<int, int>>(n);
        cin >> hx >> hy;

        for (int i = 0; i < n; ++i)
            cin >> vec[i].first >> vec[i].second;

        cin >> dx >> dy;

        if (BFS())
            cout << "happy\n";
        else
            cout << "sad\n";
    }
}
