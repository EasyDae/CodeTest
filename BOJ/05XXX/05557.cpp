//https://www.acmicpc.net/problem/5557

#include<iostream>

using namespace std;

int n;
int arr[101];
long long dp[101][21];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    dp[0][arr[0]] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 21; ++j) {
            if (dp[i - 1][j]) {
                if (j + arr[i] <= 20)
                    dp[i][j + arr[i]] += dp[i - 1][j];
                if (j - arr[i] >= 0)
                    dp[i][j - arr[i]] += dp[i - 1][j];
            }
        }
    }

    cout << dp[n - 2][arr[n - 1]];
}
