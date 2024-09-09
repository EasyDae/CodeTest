#include<iostream>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        long long y; cin >> y;
        int m; cin >> m;
 
        long long tmp = ((y - 2016) * 12) + (m - 1);
        cout << '#' << t << ' ' << tmp / 13 + 2016 << ' ' << tmp % 13 + 1 << '\n';
    }
}
