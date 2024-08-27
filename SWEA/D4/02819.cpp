#include<iostream>
#include<set>
#include<string>
 
using namespace std;
 
char arr[4][4];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
set<string> st;
 
void DFS(int x, int y, string num, int cnt) {
    if (cnt == 7) {
        st.insert(num);
        return;
    }
 
    for (int i = 0; i < 4; ++i) {
        int ax = x + dx[i];
        int ay = y + dy[i];
 
        if (ax < 0 || ax >= 4 || ay < 0 || ay >= 4) continue;
 
        DFS(ax, ay, num + arr[ax][ay], cnt + 1);
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        st.clear();
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                cin >> arr[i][j];
 
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                DFS(i, j, "", 0);
 
        cout << '#' << t << ' ' << st.size() << '\n';
    }
}
