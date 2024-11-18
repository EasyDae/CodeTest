//https://www.acmicpc.net/problem/3063

#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        int area1 = (x2 - x1) * (y2 - y1);
        int area2 = (x4 - x3) * (y4 - y3);

        int overlap = max(0, min(x2, x4) - max(x1, x3)) * max(0, min(y2, y4) - max(y1, y3));

        cout << area1 - overlap << '\n';
    }

    return 0;
}
