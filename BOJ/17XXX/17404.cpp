//https://www.acmicpc.net/problem/17404

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int arr[1001][3], dp[1001][3];
int ans = 999999999;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

	for (int j = 0; j <= 2; j++) {
		for (int i = 0; i <= 2; i++) {
			if (i == j)
				dp[1][i] = arr[1][i];
			else
				dp[1][i] = 999999999;
		}

		for (int i = 2; i <= n; i++) {
			dp[i][0] = arr[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
			dp[i][1] = arr[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
			dp[i][2] = arr[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
		}

		for (int i = 0; i <= 2; i++) {
			if (i == j) 
				continue;
			else 
				ans = min(ans, dp[n][i]);
		}
	}
	cout << ans;
}
