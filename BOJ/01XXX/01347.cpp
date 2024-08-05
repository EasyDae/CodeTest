//https://www.acmicpc.net/problem/1374

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    vector<pair<int, int>> vec(n);
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; ++i) {
        int num; cin >> num;
        cin >> vec[i].first >> vec[i].second;
    }

    sort(vec.begin(), vec.end());
    pq.push(vec[0].second);

    for (int i = 1; i < n; ++i) {
        if (vec[i].first >= pq.top())
            pq.pop();
        pq.push(vec[i].second);
    }

    cout << pq.size();
}
