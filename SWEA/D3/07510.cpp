#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n; cin >> n;

        int num = 1, sum = 0, cnt = 0;
        for (int i = 1; i <= n; ++i) {
            sum += i;
            while (sum > n) {
                sum -= num;
                num++;
            }

            if (sum == n)
                cnt++;
        }

        cout << '#' << t << ' ' << cnt << '\n';
    }
}
