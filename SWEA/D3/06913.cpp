#include<iostream>

using namespace std;

int arr[21];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, m; cin >> n >> m;

        int max = 0;
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < m; ++j) {
                bool flag; cin >> flag;
                if (flag)
                    cnt++;
            }

            arr[i] = cnt;
            if (cnt >= max)
                max = cnt;
        }

        int cnt = 0;
        for(int i=0; i<n; ++i)
            if (arr[i] == max)
                cnt++;
        
        cout << '#' << t << ' ' << cnt << ' ' << max << '\n';
    }
}
