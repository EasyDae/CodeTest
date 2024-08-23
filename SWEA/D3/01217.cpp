#include<iostream>

using namespace std;

int n, m;

int POW(int sum, int cnt) {
    if (cnt == m)
        return sum;
    else
        POW(sum * n, cnt + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int t = 1; t <= 10; ++t) {
        int c; cin >> c;
        cin >> n >> m;
        cout << '#' << t << ' ' << POW(n, 1) << '\n';
    }
}
