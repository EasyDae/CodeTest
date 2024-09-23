#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n; cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> arr[i];

        vector<int> vec;
        for (int i = 1; i <= n; ++i) {
            if (vec.empty() || vec.back() < arr[i])
                vec.push_back(arr[i]);
            else {
                int left = 0, right = vec.size() - 1;
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
        cout << '#' << t << ' ' << vec.size() << '\n';
    }
}
