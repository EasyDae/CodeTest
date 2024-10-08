#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        long long a, b; cin >> a >> b;
        cout << '#' << t << ' ' << (a/b)*(a/b) << '\n';
    }
}
