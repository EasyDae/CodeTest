//https://www.acmicpc.net/problem/13702

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k; cin >> n >> k;

    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    sort(arr, arr + n);

    long long left = 1, right = arr[n - 1];
    while (left <= right)
    {
        long long mid = (left + right) / 2;
        int cnt = 0;
        
        for (int i = 0; i < n; ++i)
            cnt += arr[i] / mid;

        if (cnt >= k)
            left = mid + 1;
        else
            right = mid - 1;
    }
    cout << right;
}
