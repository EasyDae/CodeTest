#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        vector<string> vec(5);
        int maxlen = 0;
        for (int i = 0; i < 5; ++i) {
            cin >> vec[i];
            maxlen = max(maxlen, (int)vec[i].size());
        }

        cout << '#' << t << ' ';
        for (int i = 0; i < maxlen; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (i >= vec[j].size())
                    continue;
                cout << vec[j][i];
            }
        }
        cout << '\n';
    }
}
