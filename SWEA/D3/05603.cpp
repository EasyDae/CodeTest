#include<iostream>

using namespace std;

int arr[10000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, sum = 0; cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            sum += arr[i];
        }

        int avg = sum / n, ans = 0;
        for (int i = 0; i < n; ++i)
            ans += arr[i] > avg ? arr[i] - avg : 0;

        cout << '#' << t << ' ' << ans << '\n';
    }
}
