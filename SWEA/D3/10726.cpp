#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, m; cin >> n >> m;
        int cnt = 0;
        cout << '#' << t << ' ';
        while (m) {
            if (m % 2)
                cnt++;
            else
                break;

            m /= 2;
        }
        if (cnt >= n)
            cout << "ON\n";
        else
            cout << "OFF\n";
    }
}
