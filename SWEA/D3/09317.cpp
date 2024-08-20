#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    for (int i = 1; i <= t; ++i) {
        int n, cnt = 0; cin >> n;
        string s1, s2; cin >> s1 >> s2;
        for (int i = 0; i < n; ++i)
            if (s1[i] == s2[i])
                cnt++;
        
        cout << '#' << i << ' ' << cnt << '\n';
    }
}
