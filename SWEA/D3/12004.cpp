#include<iostream>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n; cin >> n;
 
        bool flag = 0;
        for (int i = 1; i < 10; ++i) {
            for (int j = 1; j < 10; ++j)
                if (i * j == n) {
                    flag = 1;
                    break;
                }
            if (flag)
                break;
        }
 
        string ans;
        flag == 1 ? ans = "Yes" : ans = "No";
        cout << '#' << t << ' ' << ans << '\n';
    }
}
