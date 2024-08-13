//https://www.acmicpc.net/problem/4485

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, arr[126][126];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int BFS() {
    vector<vector<int>> vec(n, vector<int>(n, 20000));
    queue<pair<int, int>> q;
    q.push({ 0,0 });

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        vec[0][0] = arr[0][0];
        for (int i = 0; i < 4; ++i) {
            int ax = x + dx[i];
            int ay = y + dy[i];

            if (ax < 0 || ax >= n || ay < 0 || ay >= n)
                continue;

            if (vec[ax][ay] > vec[x][y] + arr[ax][ay]) {
                vec[ax][ay] = vec[x][y] + arr[ax][ay];
                q.push({ ax,ay });
            }
        }
    }

    return vec[n - 1][n - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 0;

    while (1) {
        cin >> n;
        if (n == 0)
            return 0;

        T++;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> arr[i][j];

        cout << "Problem " << T << ": " << BFS() << '\n';
    }
    
}
