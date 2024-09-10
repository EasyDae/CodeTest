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
        vector<int> vec(n), vec1, vec2;

        for (int i = 0; i < n; ++i)
            cin >> vec[i];

        sort(vec.begin(), vec.end());
        for (int i = 0; i < n; ++i) {
            if (i % 2)
                vec2.push_back(vec[i]);
            else
                vec1.push_back(vec[i]);
        }

        sort(vec2.begin(), vec2.end(), greater<int>());
        vec1.insert(vec1.end(), vec2.begin(), vec2.end());

        int Max = 0;
        for (int i = 1; i < n; ++i)
            Max = max(Max, abs(vec1[i] - vec1[i - 1]));

        Max = max(Max, vec1[n - 1] - vec1[0]);
        cout << '#' << t << ' ' << Max << '\n';
    }
}
