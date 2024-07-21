//https://www.acmicpc.net/problem/16926

#include <iostream>
#include <cmath>

using namespace std;

int n, m, r;
int arr[301][301];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void Rotate()
{
    int tmp[301][301];
    for (int rot = 0; rot < min(n, m) / 2; rot++) 
    {
        int x1 = rot, y1 = rot, x2 = n - 1 - rot, y2 = m - 1 - rot;
        for (int i = y2 - 1; i >= y1; i--) 
            tmp[x1][i] = arr[x1][i + 1];
        for (int i = x1 + 1; i <= x2; i++) 
            tmp[i][y1] = arr[i - 1][y1];
        for (int i = y1 + 1; i <= y2; i++) 
            tmp[x2][i] = arr[x2][i - 1];
        for (int i = x2 - 1; i >= x1; i--) 
            tmp[i][y2] = arr[i + 1][y2];
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            arr[i][j] = tmp[i][j];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> r;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> arr[i][j];

    while (r--)
        Rotate();

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cout << arr[i][j] << ' ';
        cout << '\n';
    }
}
