#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        string s; cin >> s;
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.size(); ++i) {
            switch (s[i]) {
            case 'b':
                s[i] = 'd';
                break;
            case 'd':
                s[i] = 'b';
                break;
            case 'p':
                s[i] = 'q';
                break;
            case'q':
                s[i] = 'p';
                break;
            }
        }
        cout << '#' << t << ' ' << s << '\n';
    }
}
