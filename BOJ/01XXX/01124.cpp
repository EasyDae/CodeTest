//https://www.acmicpc.net/problem/1124

#include<iostream>

using namespace std;

bool prime[100001];
int arr[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, ans = 0;
    cin >> a >> b;

    prime[0] = prime[1] = 1;
    for (int i = 2; i <= 100000; ++i)
        if (!prime[i])
            for (int j = 2 * i; j <= b; j += i) {
                prime[j] = 1;
                int tmp = j;
                while (!(tmp % i)) {
                    tmp /= i;
                    arr[j]++;
                }
            }

    for (int i = a; i <= b; ++i)
        if (!prime[arr[i]])
            ans++;

    cout << ans;
}
