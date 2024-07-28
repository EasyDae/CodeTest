//https://www.acmicpc.net/problem/1806

#include<iostream>

using namespace std;

int arr[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s; cin >> n >> s;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int left = 0, right = 0, sum = 0, Min = 100001;
    while (left <= right) {
        if (sum >= s) {
            Min = min(Min, right - left);
            sum -= arr[left++];
        }
        else if (right == n)
            break;
        else
            sum += arr[right++];
    }

    if (Min == 100001)
        cout << 0;
    else
        cout << Min;
}
