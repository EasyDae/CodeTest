#include<iostream>
#include<algorithm>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << '#' << t << ' ';
 
        int a, b; cin >> a >> b;
        int arr[41] = { 0, };
 
        for (int i = 1; i <= a; ++i)
            for (int j = 1; j <= b; ++j)
                arr[i + j]++;
 
        int Max = 0;
        for (int i = 1; i <= a + b; ++i)
            Max = max(Max, arr[i]);
 
        for (int i = 1; i <= a + b; ++i)
            if (arr[i] == Max)
                cout << i << ' ';
        cout << '\n';
    }
}
