#include<iostream>

using namespace std;

int arr[300001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, d; cin >> n >> d;

        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i]) continue;

            int cnt = 0;
            for (int j = 0; j < d; ++j) {
                if (arr[i + j] || i + j >= n)
                    break;
                else
                    cnt++;

                if (cnt == d) {
                    ans++;
                    arr[i + d - 1] = 1;
                }
            }
        }

        cout << '#' << t << ' ' << ans << '\n';
    }
}
