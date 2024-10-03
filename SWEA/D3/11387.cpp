#include<iostream>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        long long d, l, n; cin >> d >> l >> n;
        cout << '#' << t << ' ' << (d * n) + ((d * l * n * (n - 1)) / 200) << '\n';
    }
}
