#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

string Plus(string s1, string s2) {
    if (s1.size() < s2.size())
        swap(s1, s2);

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    int check = 0;
    string ans = "";
    for (int i = 0; i < s1.size(); ++i) {
        int a = s1[i] - '0';
        int b = i < s2.size() ? s2[i] - '0' : 0;
        int sum = a + b + check;
        check = sum / 10;
        ans.push_back(sum % 10 + '0');
    }
    if (check)
        ans.push_back(check + '0');

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        string s1, s2; cin >> s1 >> s2;
        cout << '#' << t << ' ' << Plus(s1, s2) << '\n';
    }
}
