//https://www.acmicpc.net/problem/31561

#include<iostream>
#include<iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m; cin >> m;
    double ans = 0.0;
    if (m / 30) {
        ans += 15;
        ans += (m % 30) / 2.0 * 3.0;
    }
    else
        ans += m / 2.0;
    
    cout << fixed << setprecision(1) << ans;
}
