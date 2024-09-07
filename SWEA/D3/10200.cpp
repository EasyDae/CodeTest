#include<iostream>
#include<algorithm>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, a, b; cin >> n >> a >> b;
        cout << '#' << t << ' ' << min(a, b) << ' ';
        if (a + b > n)
            cout << a + b - n << '\n';
        else
            cout << 0 << '\n';
    }
}
