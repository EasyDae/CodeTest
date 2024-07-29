#include<iostream>

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
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'a' + i)
                cnt++;
            else
                break;
        }

        cout << '#' << test_case << ' ' << cnt << '\n';
    }
    return 0;
}
