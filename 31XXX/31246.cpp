//https://www.acmicpc.net/problem/31246

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k; cin >> n >> k;

    int cnt = 0;
    vector<int> vec;
    for (int i = 0; i < n; ++i)
    {
        int a, b; cin >> a >> b;
        if (a >= b)
            cnt++;
        else
            vec.push_back(b - a);
    }

    sort(vec.begin(), vec.end());

    if (k - cnt <= 0)
        cout << 0;
    else
        cout << vec[k - cnt - 1];
}
