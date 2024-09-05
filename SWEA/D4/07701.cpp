#include<iostream>
#include<vector>
#include<algorithm>
 
using namespace std;
 
bool comp(string s1, string s2) {
    if (s1.size() != s2.size())
        return s1.size() < s2.size();
    else
        return s1 < s2;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n; cin >> n;
        vector<string> vec(n);
         
        for (int i = 0; i < n; ++i)
            cin >> vec[i];
 
        sort(vec.begin(), vec.end(), comp);
 
        cout << '#' << t << '\n' << vec[0] << '\n';
        string prev = vec[0];
        for (int i = 1; i < n; ++i) {
            if (vec[i] != prev) {
                prev = vec[i];
                cout << vec[i] << '\n';
            }
        }
    }
}
