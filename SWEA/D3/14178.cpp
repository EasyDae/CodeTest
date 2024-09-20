#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, d; cin >> n >> d;
        if (n % (2 * d + 1))
            cout << '#' << t << ' ' << n / (2 * d + 1) + 1 << '\n';
        else
            cout << '#' << t << ' ' << n / (2 * d + 1) << '\n';
    }
}
