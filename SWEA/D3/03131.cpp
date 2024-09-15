#include<iostream>

using namespace std;

bool prime[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    prime[0] = prime[1] = 1;
    for (int i = 2; i <= 1000000; ++i)
        if (!prime[i])
            for (int j = 2 * i; j <= 1000000; j += i)
                prime[j] = 1;

    for (int i = 2; i <= 1000000; ++i)
        if (!prime[i]) cout << i << ' ';
}
