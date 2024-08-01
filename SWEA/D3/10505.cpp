#include<iostream>
#include<vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    for (int test_case = 1; test_case <= t; ++test_case)
    {
        int n, sum = 0; cin >> n;
        vector<int> vec(n);
        for (int i = 0; i < n; ++i) {
            cin >> vec[i];
            sum += vec[i];
        }

        int average = sum / n;
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            if (vec[i] <= average)
                cnt++;
        
        cout << '#' << test_case << ' ' << cnt << '\n';
    }
    return 0;
}
