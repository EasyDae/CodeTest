//https://www.acmicpc.net/problem/19598

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n; cin >> n;

    vector<pair<int, int>> vec(n);
    priority_queue<int, vector<int>, greater<>> pq;

    for (int i = 0; i < n; ++i)
        cin >> vec[i].first >> vec[i].second;

    sort(vec.begin(), vec.end());

    pq.push(vec[0].second);
    for (int i = 1; i < n; ++i) {
        if (pq.top() <= vec[i].first) {
            pq.pop();
            pq.push(vec[i].second);
        }
        else
            pq.push(vec[i].second);
    }

    cout << pq.size();
}
