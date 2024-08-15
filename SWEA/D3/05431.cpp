#include<iostream>
#include<vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    for (int i = 1; i <= t; ++i) {
        int n, k; cin >> n >> k;

        vector<bool> vec(n + 1);
        for (int j = 0; j < k; ++j) {
            int tmp; cin >> tmp;
            vec[tmp] = 1;
        }

        cout << '#' << i << ' ';

        for (int j = 1; j <= n; ++j)
            if (!vec[j])
                cout << j << ' ';

        cout << '\n';
    }
}
