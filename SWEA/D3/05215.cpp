#include<iostream>

using namespace std;

int n, l;
int dp[21][10001];
pair<int, int> arr[21];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> n >> l;
        for (int i = 1; i <= n; ++i)
            cin >> arr[i].first >> arr[i].second;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= l; ++j) {
                if (arr[i].second > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i].second] + arr[i].first);
            }
        }

        cout << '#' << t << ' ' << dp[n][l] << '\n';
    }
}
