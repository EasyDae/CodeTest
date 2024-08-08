//https://www.acmicpc.net/problem/1715

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        pq.push(a);
    }

    if (n == 1) {
        cout << 0;
        return 0;
    }

    int ans = 0;
    while (!pq.empty()) {
        int sum = 0;
        sum += pq.top();
        pq.pop();
        if (!pq.empty()) {
            sum += pq.top();
            pq.pop();
            if (!pq.empty())
                pq.push(sum);
        }
        ans += sum;
    }

    cout << ans;
}
