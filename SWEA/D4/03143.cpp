#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        string a, b; cin >> a >> b;
        int cnt = 0;
        int len = b.size();
        for (int i = 0; i < a.size(); ++i) {
            if (a.substr(i, len) == b) {
                cnt++;
                i += len - 1;
            }else cnt++;
        }

        cout << '#' << t << ' ' << cnt << '\n';
    }
}
