//https://www.acmicpc.net/problem/20162

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr[1001], dp[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, Max = 0; cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    dp[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        dp[i] = arr[i];
        for (int j = 0; j < i; ++j)
            if (arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + arr[i]);

        Max = max(Max, dp[i]);
    }

    cout << Max;
}
