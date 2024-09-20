#include<iostream>
#include<string.h>
 
using namespace std;
 
bool check[501][501];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        memset(check, 0, sizeof(check));
        int n, m; cin >> n >> m;
        for (int i = 0; i < m; ++i) {
            int a, b; cin >> a >> b;
            check[a][b] = true;
        }
 
        for (int k = 1; k <= n; ++k)
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    if (check[i][k] && check[k][j])
                        check[i][j] = true;
 
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int cnt = 0;
            for (int j = 1; j <= n; ++j)
                if (check[i][j] || check[j][i])
                    cnt++;
 
            if (cnt == n - 1)
                ans++;
        }
 
        cout << '#' << t << ' ' << ans << '\n';
    }
}
