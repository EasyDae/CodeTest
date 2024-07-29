//https://www.acmicpc.net/problem/12738

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
int arr[1000001], dp[1000001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];

    vector<int> vec;

    for (int i = 1; i <= n; ++i) {
        if (vec.empty() || vec.back() < arr[i])
            vec.push_back(arr[i]);
        else {
            int left = 0, right = vec.size()  - 1;
            while (left < right) {
                int mid = (left + right) / 2;
                if (vec[mid] >= arr[i])
                    right = mid;
                else
                    left = mid + 1;
            }
            vec[left] = arr[i];
        }
    }

    cout << vec.size();
}
