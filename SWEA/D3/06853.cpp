#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int ans[3] = { 0, };
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        int n; cin >> n;
        for (int i = 0; i < n; ++i) {
            int x, y; cin >> x >> y;
            if((x > x1 && x < x2) && (y > y1 && y < y2))
                ans[0]++;
            else if((x == x1 && y >= y1 && y <= y2) || (x == x2 && y >= y1 && y <= y2) || (y == y1 && x >= x1 && x <= x2) || (y == y2 && x >= x1 && x <= x2))
                ans[1]++;
            else
                ans[2]++;
        }
        cout << '#' << t << ' ' << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
    }
}
