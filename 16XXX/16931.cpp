//https://www.acmicpc.net/problem/16931

#include <iostream>

using namespace std;

int n, m;
int arr[102][102];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    int sum = 2 * n * m;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> arr[i][j];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            for (int k = 0; k < 4; ++k)
            {
                int x = i + dx[k];
                int y = j + dy[k];

                if (arr[x][y] < arr[i][j])
                    sum += arr[i][j] - arr[x][y];
            }

    cout << sum;
}
