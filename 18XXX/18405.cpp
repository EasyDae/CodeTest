//https://www.acmicpc.net/problem/18405

#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int n, k, s, X, Y;
int arr[201][201];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    deque<tuple<int, int, int, int>> dq;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> arr[i][j];
            if (arr[i][j])
                dq.push_back({ arr[i][j], i, j, 0 });
        }
    }  
    cin >> s >> X >> Y;

    sort(dq.begin(), dq.end());
    int x, y, time, virus;
    while (!dq.empty()) {
        tie(virus, x, y, time) = dq.front();
        dq.pop_front();
        if (time == s) break;
        else {
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 1 && ny >= 1 && nx <= n && ny <= n && arr[nx][ny] == 0) {
                    arr[nx][ny] = virus;
                    dq.push_back({ virus, nx, ny, time + 1 });
                }
            }
        }
    }

    cout << arr[X][Y];
}
