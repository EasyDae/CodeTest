//https://www.acmicpc.net/problem/23320

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    vector<int> vec(n);

    for (int i = 0; i < n; ++i)
        cin >> vec[i];

    sort(vec.begin(), vec.end(), greater());

    int X, Y; cin >> X >> Y;

    int s = n/10 * X/10, j = 0;

    for (int i = 0; i < n; ++i)
    {
        if (vec[i] >= Y)
            j++;
        else
            break;
    }
    
    cout << s << ' ' << j;
}
