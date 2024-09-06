#include<iostream>
#include<algorithm>

using namespace std;

int arr[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int a, b, c; cin >> a >> b >> c;
        cout << '#' << t << ' ' << max(c / a, c / b) << '\n';
    }
}
