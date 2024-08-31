#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
 
using namespace std;
 
int n;
vector<pair<int, int>> vec;
vector<int> ans;
bool visited[22];
 
void DFS(vector<int> v) {
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            if (vec[i].first == vec[v.back()].second) {
                visited[i] = true;
                v.push_back(i);
                DFS(v);
                v.pop_back();
            }
        }
    }
 
    if (v.size() > ans.size()) {
        ans = v;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        ans.clear();
 
        cin >> n;
        vec = vector<pair<int, int>>(n + 1);
        for (int i = 0; i < n; ++i)
            cin >> vec[i].first >> vec[i].second;
         
        for (int i = 0; i < n; ++i) {
            memset(visited, 0, sizeof(visited));
            visited[i] = 1;
            vector<int> v;
            v.push_back(i);
            DFS(v);
        }
 
        cout << '#' << t << ' ';
        for (auto& x : ans)
            cout << vec[x].first << ' ' << vec[x].second << ' ';
        cout << '\n';
    }
}
