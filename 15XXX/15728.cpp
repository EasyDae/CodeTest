//https://www.acmicpc.net/problem/15728

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, K; cin >> n >> K;
    vector<int> vec1(n), vec2(n);

    for (int i = 0; i < n; ++i)
        cin >> vec1[i];

    for (int i = 0; i < n; ++i)
        cin >> vec2[i];

    long max = -100000000;
    int idx = 0;
    for (int i = 0; i < K + 1; ++i)
    {
        max = -100000000;
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n - i; ++k)
            {
                if (max < vec1[j] * vec2[k])
                {
                    max = vec1[j] * vec2[k];
                    idx = k;
                }
            }
        }

        vec2.erase(vec2.begin() + idx);
    }

    cout << max;
}
