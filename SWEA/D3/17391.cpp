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
        int n; cin >> n;
        string s; cin >> s;
        if (n % 2) {
            cout << '#' << test_case << ' ' << "No\n";
            continue;
        }

        string s1 = s.substr(0, s.size() / 2), s2 = s.substr(s.size()/2, s.size());
        if(s1 == s2)
            cout << '#' << test_case << ' ' << "Yes\n";
        else
            cout << '#' << test_case << ' ' << "No\n";
    }
    return 0;
}
