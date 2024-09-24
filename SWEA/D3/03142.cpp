#include<iostream>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n,m, ans1, ans2; cin >> n >> m;
        ans1 = (m * 2) - n;
        ans2 = n - m;
        
        cout << '#' << t << ' ' << ans1 << ' ' << ans2 << '\n';
    }
}
