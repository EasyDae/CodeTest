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
        string s;
        int n;
        cin >> s >> n;
        vector<int> vec(n);
 
        int len = s.size();
        for (int i = 0; i < n; i++)
            cin >> vec[i];
        sort(vec.begin(), vec.end());
 
        int cnt = 0;
        for (int i = 0; i < n; i++){
            if (vec[i] == len)
                s += "-";
            else
                s.insert(vec[i] + cnt++, "-");
        }
        cout << '#' << t << " " << s << '\n';
    }
}
