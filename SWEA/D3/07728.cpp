#include<iostream>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        string s; cin >> s;
        bool arr[10] = { 0, };
 
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i){
            if (!arr[s[i] - '0']) {
                arr[s[i] - '0'] = 1;
                cnt++;
            }
        }
 
        cout << '#' << t << ' ' << cnt << '\n';
    }
}
