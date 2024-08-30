#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n; cin >> n;
        cout << '#' << t << ' ' << n / 30 << ' ' << (n % 30) * 2 << '\n';
    }
}
