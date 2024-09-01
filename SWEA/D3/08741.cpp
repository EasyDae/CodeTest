#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        string a, b, c; cin >> a >> b >> c;
        a[0]-=32; b[0]-=32; c[0]-=32;
        cout << '#' << t << ' ' << a[0] << b[0] << c[0] << '\n';
    }
}
