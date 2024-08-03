#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    for (int test_case = 1; test_case <= t; ++test_case)
    {
        cout << '#' << test_case << ' ';
        
        int p; cin >> p;
        vector<int> vec(p);

        for (int i = 0; i < p; ++i)
            cin >> vec[i];

        if (p == 1) {
            cout << vec[0] * vec[0] << '\n';
            continue;
        }

        sort(vec.begin(), vec.end());

        cout << vec[0] * vec[p - 1] << '\n';
    }
    return 0;
}
