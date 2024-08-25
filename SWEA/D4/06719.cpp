#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, k; cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; ++i)
            cin >> vec[i];
        sort(vec.begin(), vec.end());
        
        double ans = 0;
        for (int i = n - k; i < n; ++i) {
            ans = (ans + vec[i]) / 2;
        }

        cout << '#' << t << ' ' << fixed << setprecision(6) << ans << '\n';
    }
}
