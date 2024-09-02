#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, k; cin >> n >> k;
        vector<int> vec(n);

        for (int i = 0; i < n; ++i)
            cin >> vec[i];

        sort(vec.begin(), vec.end(), greater<int>());
        int ans = accumulate(vec.begin(), vec.begin() + k, 0);

        cout << '#' << t << ' ' << ans << '\n';
    }
}
