#include<iostream>
#include<vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, m; cin >> n >> m;
        vector<int> vec(n);

        for (int i = 0; i < n; ++i)
            cin >> vec[i];

        int ans = 0, cost = 0, idx = 1;
        for (int i = 0; i < n; ++i) {
            cost += vec[i];
            while (cost > m)
                cost -= vec[idx++];

            if (cost == m)
                ans++;
        }

        cout << '#' << t << ' ' << ans << '\n';
    }
}
