#include<iostream>

using namespace std;

int arr[26] = { 1,2,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        string s1, s2; cin >> s1 >> s2;
        if (s1.size() != s2.size()) {
            cout << '#' << t << ' ' << "DIFF\n";
            continue;
        }

        bool flag = 1;
        for (int i = 0; i < s1.size(); ++i) {
            if (arr[s1[i] - 'A'] != arr[s2[i] - 'A']) {
                cout << '#' << t << ' ' << "DIFF\n";
                flag = 0;
                break;
            }
        }

        if(flag)
            cout << '#' << t << ' ' << "SAME\n";
    }
}
