#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    for (int i = 1; i <= t; ++i) {
        int n; cin >> n;
        vector<int> vec(n);

        for (int i = 0; i < n; ++i)
            cin >> vec[i];

        sort(vec.begin(), vec.end(), greater<int>());

        long ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (!(i % 3))
                continue;

            ans += vec[i - 1];
        }

        cout << '#' << i << ' ' << ans << '\n';
    }
}
