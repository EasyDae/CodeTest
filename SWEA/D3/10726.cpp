#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, m; cin >> n >> m;
        while (m != 0 && n != 0) {
            if (m % 2)
                n--;
            else
                break;
            m /= 2;
        }
        if (!n)
            cout << '#' << t << ' ' << "ON\n";
        else
            cout << '#' << t << ' ' << "OFF\n";
    }
}
