#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        
        string s; cin >> s;
        int tmp = stoi(s);
        bool flag = false;
        while (next_permutation(s.begin(), s.end())) {
            if (!(stoi(s) % tmp) && stoi(s) / tmp > 0) {
                flag = 1;
                break;
            }
        }
        
        if (flag)
            cout << '#' << t << ' ' << "possible\n";
        else
            cout << '#' << t << ' ' << "impossible\n";
    }
}
