#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

vector<vector<int>> vec;
int cnt[101];
int n, s;

void init(){
    for(int i = 0; i <= 100; ++i)
        cnt[i] = 0;
}

void BFS() {
    queue<int> q;
    q.push(s);
    cnt[s] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < vec[cur].size(); ++i) {
            int next = vec[cur][i];
            if (!cnt[next]) {
                cnt[next] = cnt[cur] + 1;
                q.push(next);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int t = 1; t <= 10; ++t) {
        init();
        int ans = 0;
        cin >> n >> s;
        vec = vector<vector<int>>(101);
        for (int i = 0; i < n / 2; ++i) {
            int a, b; cin >> a >> b;
            vec[a].push_back(b);
        }

        BFS();
        int maxval = 0;
        for (int i = 100; i >= 0; --i){
            if(cnt[i] > maxval) {
            	maxval = max(maxval, cnt[i]);
                ans = i;
            }
        }

        cout << "#" << t << " " << ans << endl;
    }
}
