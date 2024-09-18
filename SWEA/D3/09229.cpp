#include<iostream>
#include<algorithm>

using namespace std;

int arr[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, m; cin >> n >> m;
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        sort(arr, arr + n);

        int left = 0, right = n - 1, ans = 0;
        while (left < right) {
            int sum = arr[left] + arr[right];
            if (sum == m) {
                ans = m;
                break;
            }
            else if (sum < m) {
                ans = max(ans, sum);
                left++;
            }
            else
                right--;
        }
        if (!ans)
            ans = -1;

        cout << '#' << t << ' ' << ans << '\n';
    }
}
