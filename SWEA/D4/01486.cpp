#include<iostream>
#include<algorithm>

using namespace std;

bool visited[21];
int arr[21];
int n, b, ans;

void DFS(int idx, int sum) {
    if (sum >= b) {
        ans = min(ans, sum - b);
        return;
    }

    for (int i = idx; i < n; ++i) {
        if (!visited[i]) {
            visited[i] = 1;
            DFS(i, sum + arr[i]);
            visited[i] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        ans = 200001;
        cin >> n >> b;
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        DFS(0, 0);

        cout << '#' << t << ' ' << ans << '\n';
    }
}
