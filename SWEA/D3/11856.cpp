#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int arr[26] = {0,};
        string s; cin >> s;
        for (int i = 0; i < 4; ++i)
            arr[s[i] - 'A']++;

        bool flag = 1;
        for (int i = 0; i < 26; ++i) {
            if (arr[i] != 0 && arr[i] != 2) {
                flag = 0;
                break;
            }
        }

        cout << '#' << t << ' ';
        if (flag) cout << "Yes\n";
        else cout << "No\n";
    }
}
