#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int Max = 0, Min = 100;

        for (int i = 0; i < 10; ++i) {
            string s; cin >> s;
            int tmp = 0;
            for (int j = 0; j < s.size(); ++j)
                tmp += s[j] - '0';

            Max = max(Max, tmp);
            Min = min(Min, tmp);
        }

        cout << '#' << t << ' ' << Max << ' ' << Min << '\n';
    }
}
