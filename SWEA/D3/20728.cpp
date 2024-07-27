#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int n, k; cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; ++i)
            cin >> vec[i];

        sort(vec.begin(), vec.end());

        int Min = 2147483647;

        if (n == k)
            Min = vec[n - 1] - vec[0];
        else{
            for (int i = 0; i <= n - k; ++i)
                for (int j = i + k - 1; j < n; ++j)
                    Min = min(Min, vec[j] - vec[i]);
        }

        cout << '#' << test_case << ' ' << Min << '\n';
    }
    return 0;
}
