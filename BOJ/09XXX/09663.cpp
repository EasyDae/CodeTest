//https://www.acmicpc.net/problem/9663

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int arr[15];
int n, cnt = 0;

bool check(int col) {
    for (int i = 0; i < col; ++i)
        if (arr[i] == arr[col] || abs(arr[col] - arr[i]) == col - i)
            return false;
    
    return true;
}

void queen(int a) {
    if (a == n)
        cnt++;
    else {
        for (int i = 0; i < n; ++i) {
            arr[a] = i;
            if (check(a))
                queen(a + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    queen(0);
    cout << cnt;
}
