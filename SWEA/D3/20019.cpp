#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        string s; cin >> s;
        int len = s.size();
        string tmp1 = s;
        reverse(tmp1.begin(), tmp1.end());

        if (tmp1 != s) {
            cout << '#' << test_case << ' ' << "NO\n";
            continue;
        }

        string s1 = s.substr(0, (len - 1) / 2), s2 = tmp1.substr(0, (len - 1) / 2);
        string tmp2 = s1, tmp3 = s2;
        reverse(tmp2.begin(), tmp2.end());
        reverse(tmp3.begin(), tmp3.end());

        if (tmp2 != s1) {
            cout << '#' << test_case << ' ' << "NO\n";
            continue;
        }

        if (tmp3 != s2) {
            cout << '#' << test_case << ' ' << "NO\n";
            continue;
        }

        cout << '#' << test_case << ' ' << "YES\n";
    }
    return 0;
}
