#include<iostream>
#include<vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, q; cin >> n >> q;
        vector<int> vec(n);

        for (int i = 1; i <= q; ++i) {
            int l, r; cin >> l >> r;
            for (int j = l - 1; j < r; ++j)
                vec[j] = i;
        }

        cout << '#' << t << ' ';
        for (int i = 0; i < n; ++i)
            cout << vec[i] << ' ';
        cout << '\n';
    }
}
