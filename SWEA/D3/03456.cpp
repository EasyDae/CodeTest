#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    for (int i = 1; i <= t; ++i) {
        int a, b, c; cin >> a >> b >> c;
        if (a == b)
            cout << '#' << i << ' ' << c << '\n';
        else if(b==c)
            cout << '#' << i << ' ' << a << '\n';
        else
            cout << '#' << i << ' ' << b << '\n';
    }
}
