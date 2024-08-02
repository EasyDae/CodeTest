#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

string S, E;
bool flag;

void func(string s) {
    if (s.size() == S.size()) {
        if (s == S)
            flag = 1;

        return;
    }

    if (s[s.size() - 1] == 'X') {
        string tmp = s;
        tmp.pop_back();
        func(tmp);
    }

    if (s[0] == 'Y') {
        string tmp = s;
        reverse(tmp.begin(), tmp.end());
        tmp.pop_back();
        func(tmp);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    for (int test_case = 1; test_case <= t; ++test_case)
    {
        cout << '#' << test_case << ' ';
        flag = 0;

        cin >> S >> E;
        func(E);

        if (flag)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
