#include<iostream>
#include<vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n; cin >> n;
        int mid = (n + 1) / 2;
        vector<string> vec1, vec2;
        for (int i = 0; i < n; ++i) {
            string s; cin >> s;
            if (i >= mid)
                vec2.push_back(s);
            else
                vec1.push_back(s);
        }

        cout << '#' << t << ' ';
        for (int i = 0; i < mid; ++i) {
            cout << vec1[i] << ' ';
            if (vec2.size() != i)
                cout << vec2[i] << ' ';
        }
        
        cout << '\n';
    }
}
