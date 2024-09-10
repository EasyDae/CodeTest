#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n; cin >> n;
        vector<int> vec(n);

        for (int i = 0; i < n; ++i)
            cin >> vec[i];

        int ans = 0;
        for (int i = 1; i < n - 1; ++i) {
            int MaxV = max(vec[i - 1], max(vec[i], vec[i + 1]));
            int MinV = min(vec[i - 1], min(vec[i], vec[i + 1]));

            if (vec[i] != MaxV && vec[i] != MinV) 
                ans++;
        }

        cout << '#' << t << ' ' << ans << '\n';
    }
}
