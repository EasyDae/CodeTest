#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        string s; cin >> s;
        int arr[26] = { 0, };
        for (auto& x : s)
            arr[x - 'a']++;

        cout << '#' << t << ' ';

        bool flag = 1;
        for (int i = 0; i < 26; ++i) {
            if (arr[i] % 2) {
                cout << (char)(i + 'a');
                flag = 0;
            }
        }

        if (flag) cout << "Good\n";
        else cout << '\n';
    }
}
