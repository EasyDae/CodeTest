#include <iostream>
#include <cmath>

using namespace std;

int n, m, r;
int arr[301][301];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void Rotate(int start, int size) {
    int repeat = r % size;

    while (repeat--) {
        int val = arr[start][start];
        int x = start;
        int y = start;
        int k = 0;

        while (k < 4) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx == start && ny == start) break;
            if ((start <= nx && nx < n - start) && (start <= ny && ny < m - start)) {
                arr[x][y] = arr[nx][ny];
                x = nx;
                y = ny;
            }
            else 
                k++;
        }
        arr[start + 1][start] = val;
    }
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

    int N = n, M = m;
    int mapSize = min(n, m) / 2;

    for (int i = 0; i < mapSize; i++) {
        Rotate(i, N * 2 + (M - 2) * 2);

        N -= 2;
        M -= 2;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
            cout << arr[i][j] << " ";
        cout << "\n";
    }
}
