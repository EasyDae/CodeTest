#include<iostream>
#include<cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, p; cin >> n >> p;
        cout << '#' << t << ' ' << (long long)(pow(n / p, p - (n % p)) * pow(n / p + 1, n % p)) << '\n';
    }
}
