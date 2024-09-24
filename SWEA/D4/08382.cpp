#include<iostream>
#include<algorithm>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        int dist1 = abs(a-c);
        int dist2 = abs(b-d);
        
        if(abs(dist1 + dist2) % 2)
            cout << '#' << t << ' ' << max(dist1, dist2) * 2 - 1 << '\n';
        else
            cout << '#' << t << ' ' << max(dist1, dist2) * 2 << '\n';
    }
}
