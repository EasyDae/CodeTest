#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int d, h, m; cin >> d >> h >> m;
        int ans = (d * 24 * 60 + h * 60 + m) - (11 * 24 * 60 + 11 * 60 + 11);
        if (ans < 0)
            ans = -1;

        cout << '#' << t << ' ' << ans << '\n';
    }
}
