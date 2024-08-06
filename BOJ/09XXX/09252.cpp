//https://www.acmicpc.net/problem/9252

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1, s2, ans; cin >> s1 >> s2;
    int len1 = s1.size(), len2 = s2.size();

    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    
    int row = len1, col = len2;

    while (dp[row][col]) {
        if (dp[row][col] == dp[row - 1][col])
            row--;
        else if (dp[row][col] == dp[row][col - 1])
            col--;
        else {
            ans += s2[col - 1];
            row--, col--;
        }
    }

    cout << dp[len1][len2] << '\n';
    if (ans.size() > 0) {
        reverse(ans.begin(), ans.end());
        cout << ans;
    }
}
