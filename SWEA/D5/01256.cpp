#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    for (int test_case = 1; test_case <= t; ++test_case)
    {
        cout << '#' << test_case << ' ';
        
        int k; string s; cin >> k >> s;
        vector<string> vec;

        for (int i = 0; i < s.size(); ++i) {
            string tmp = s.substr(i, s.size());
            vec.push_back(tmp);
        }

        sort(vec.begin(), vec.end());
        cout << vec[k - 1] << '\n';
    }
    return 0;
}
