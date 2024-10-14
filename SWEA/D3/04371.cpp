#include<iostream>
#include<vector>
 
using namespace std;
 
vector<bool> check(1000000000, 0);
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int cnt = 0;
        int n; cin >> n;
        vector<int> vec(n);
        for (int i = 0; i < n; ++i) {
            cin >> vec[i];
            check[vec[i]] = 1;
            vec[i]--;
        }
 
        int Max = vec.back() + 1, Size = n - 1;
        for (int i = 1; i < vec.size(); ++i) {
            bool flag = 0;
            for (int j = 1 + vec[i]; j <= Max; j += vec[i]) {
                if (check[j]) {
                    flag = 1;
                    check[j] = 0;
                    Size--;
                }
            }
 
            if (flag) cnt++;
            if (Size < 1)
                break;
        }
 
        cout << '#' << t << ' ' << cnt << '\n';
    }
}
