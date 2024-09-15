#include<iostream>
#include<cmath>

using namespace std;

int arr[100001];
int arr2[100001];

void countDiv(int n) {
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); ++i) {
        if (!(n % i)) {
            if (i == n / i)
                cnt++;
            else
                cnt += 2;
        }
    }
    arr[n] = cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 1; i <= 100000; ++i)
        countDiv(i);

    int idx = 0, Max = 0;
    for (int i = 1; i <= 100000; ++i) {
        if (arr[i] >= Max) {
            idx = i;
            arr2[i] = idx;
            Max = arr[i];
        }
        else
            arr2[i] = idx;
    }

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n; cin >> n;
        cout << '#' << t << ' ' << arr2[n] << '\n';
    }
}
