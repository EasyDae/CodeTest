#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        vector<char> vec;
        string s; cin >> s;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            auto var = find(vec.begin(), vec.end(), c);
            if (var != vec.end())
                vec.erase(var);
            else
                vec.push_back(c);
        }
        cout << '#' << t << ' ' << vec.size() << '\n';
    }
}
