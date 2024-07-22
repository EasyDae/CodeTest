//https://www.acmicpc.net/problem/13398

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[100001][2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    vector<int> vec(n);

    for (int i = 0; i < n; ++i)
        cin >> vec[i];

    int Max = vec[0];
    dp[0][0] = vec[0], dp[0][1] = vec[0];
    for (int i = 1; i < n; ++i) {
        dp[i][0] = max(dp[i - 1][0] + vec[i], vec[i]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + vec[i]);
        Max = max(Max, max(dp[i][0], dp[i][1]));
    }

    cout << Max;
}
