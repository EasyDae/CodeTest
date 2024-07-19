//https://www.acmicpc.net/problem/3020

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, h;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> h;
    vector<int> top(h + 1);
    vector<int> bottom(h + 1);
    vector<int> vec(h + 1);

    for (int i = 0; i < n / 2; ++i)
    {
        int a, b; cin >> a >> b;
        bottom[a]++;
        top[h + 1 - b]++;
    }

    for (int i = h - 1; i >= 1; --i)
        bottom[i] += bottom[i + 1];

    int Min = 99999999;
    int cnt = 0;
    for (int i = 1; i <= h; ++i)
    {
        top[i] += top[i - 1];
        vec[i] += top[i] + bottom[i];
        if (vec[i] < Min)
        {
            cnt = 1;
            Min = vec[i];
        }
        else if (vec[i] == Min)
            cnt++;
    }

    cout << Min << ' ' << cnt;
}
