//https://www.acmicpc.net/problem/31797

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    vector<pair<int, int>> vec(m);
    vector<int> vec1;

    for (int i = 0; i < m; ++i)
    {
        cin >> vec[i].first >> vec[i].second;

        vec1.push_back(vec[i].first), vec1.push_back(vec[i].second);
    }

    sort(vec1.begin(), vec1.end());

    n %= (2 * m);
    if (n == 0)
        n = 2 * m;

    int tmp = vec1[n - 1];
    for (int i = 0; i < m; ++i)
    {
        if (vec[i].first == tmp || vec[i].second == tmp)
        {
            cout << i + 1;
            break;
        }
    }
}
