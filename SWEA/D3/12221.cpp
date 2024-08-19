#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    for (int i = 1; i <= t; ++i) {
        int a, b; cin >> a >> b;
        if(a>9 || b>9)
            cout << '#' << i << ' ' << -1 << '\n';
        else
            cout << '#' << i << ' ' << a*b << '\n';
    }
}
