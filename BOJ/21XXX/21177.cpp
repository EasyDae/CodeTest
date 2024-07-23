//https://www.acmicpc.net/problem/21177

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i)
        cin >> vec[i];

    sort(vec.begin(), vec.end());

    int ans = vec[0];
    for (int i = 1; i < n; ++i) {
        if (vec[i] - vec[i - 1] != 1)
            ans += vec[i];
    }

    cout << ans;
}
