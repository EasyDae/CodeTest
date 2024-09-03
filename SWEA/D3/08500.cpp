#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n; cin >> n;
        vector<int> vec(n);
        for (int i = 0; i < n; ++i)
            cin >> vec[i];

        sort(vec.begin(), vec.end(), greater<int>());

        int cnt = vec[0];
        for (int i = 0; i < n; ++i)
            cnt += vec[i] + 1;
        cout << '#' << t << ' ' << cnt << '\n';
    }
}
