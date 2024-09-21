#include<iostream>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int s, e, m; cin >> s >> e >> m;
        int ans = s;
        while (1) {
            if ((ans - s) % 365 == 0 && (ans - e) % 24 == 0 && (ans - m) % 29 == 0) {
                cout << '#' << t << ' ' << ans << '\n';
                break;
            }
            else
                ans+=365;
        }
    }
}
