#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    for (int i = 1; i <= t; ++i) {
        int n; cin >> n;
        int ascend = 0, descend = 0, prev = 0;
        cin >> prev;
        for (int j = 1; j < n; ++j) {
            int tmp; cin >> tmp;
            if (tmp < prev)
                descend = max(descend, prev - tmp);
            else if (tmp > prev)
                ascend = max(ascend, tmp - prev);

            prev = tmp;
        }

        cout << '#' << i << ' ' << ascend << ' ' << descend << '\n';
    }
}
