#include<iostream>
#include<iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n; cin >> n;

        double ans = 0;
        for (int i = 0; i < n; ++i) {
            double a, b; cin >> a >> b;
            ans += a * b;
        }

        cout << fixed << setprecision(6) << '#' << t << ' ' << ans << '\n';
    }
}
