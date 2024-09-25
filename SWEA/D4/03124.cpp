#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int parent[100010];

int Find(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    parent[b] = a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int v, e; cin >> v >> e;
        for (int i = 1; i <= v; ++i)
            parent[i] = i;

        vector<pair<int, pair<int, int>>> vec;
        for (int i = 0; i < e; ++i) {
            int a, b, c; cin >> a >> b >> c;
            vec.push_back({ c, {a, b} });
        }

        sort(vec.begin(), vec.end());

        long ans = 0;
        for (int i = 0; i < e; ++i) {
            if (Find(vec[i].second.first) != Find(vec[i].second.second)) {
                Union(vec[i].second.first, vec[i].second.second);
                ans += vec[i].first;
            }
        }

        cout << '#' << t << ' ' << ans << '\n';
    }
}
