#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    for (int i = 1; i <= t; ++i) {
        vector<int> vec(5);
        for (int i = 0; i < 5; ++i) {
            cin >> vec[i];
            if (vec[i] < 40)
                vec[i] = 40;
        }

        cout << '#' << i << ' ' << accumulate(vec.begin(), vec.end(), 0) / 5 << '\n';
    }
}
