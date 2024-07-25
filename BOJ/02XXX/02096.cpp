//https://www.acmicpc.net/problem/2096

#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

int dp[3][3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    int Max, Min, tmp1, tmp2;
    cin >> dp[1][0] >> dp[1][1] >> dp[1][2];
    dp[2][0] = dp[1][0], dp[2][1] = dp[1][1], dp[2][2] = dp[1][2];

    for (int i = 2; i <= n; ++i) {
        cin >> dp[0][0] >> dp[0][1] >> dp[0][2];

        tmp1 = dp[1][0], tmp2 = dp[1][2];
        dp[1][0] = dp[0][0] + max(dp[1][0], dp[1][1]);
        dp[1][2] = dp[0][2] + max(dp[1][1], dp[1][2]);
        dp[1][1] = dp[0][1] + max(tmp1, max(dp[1][1], tmp2));


        tmp1 = dp[2][0], tmp2 = dp[2][2];
        dp[2][0] = dp[0][0] + min(dp[2][0], dp[2][1]);
        dp[2][2] = dp[0][2] + min(dp[2][1], dp[2][2]);
        dp[2][1] = dp[0][1] + min(tmp1, min(dp[2][1], tmp2));

    }
    Max = max(dp[1][0], max(dp[1][1], dp[1][2]));
    Min = min(dp[2][0], min(dp[2][1], dp[2][2]));

    cout << Max << ' ' << Min;
}
