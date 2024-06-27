https://www.acmicpc.net/problem/15130

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> vec(11);

    int idx1 = -1, idx2 = -1, diff = 1;
    for (int i = 0; i < 10; ++i)
    {
        cin >> vec[i];
        if (vec[i])
        {
            if (idx1 == -1)
                idx1 = i;
            else
                idx2 = i;
        }
        else
            if (idx1 != -1 && idx2 == -1)
                diff++;
    }

    if ((vec[idx2] - vec[idx1]) % diff)
        cout << -1;
    else
    {
        int tmp = (vec[idx2] - vec[idx1]) / diff;

        if (tmp == 0)
            for (int i = 0; i < 10; ++i)
                cout << vec[idx1] << ' ';
        else
        {
            for (int i = 0; i < idx1; ++i)
                vec[i] = vec[idx1] - tmp * (idx1 - i);
            for (int i = idx1 + 1; i < idx2; ++i)
                vec[i] = vec[idx1] + tmp * (i - idx1);
            for (int i = idx2 + 1; i < 10; ++i)
                vec[i] = vec[idx2] + tmp * (i - idx2);

            for (int i = 0; i < 10; ++i)
                cout << vec[i] << ' ';
        }
    }
}
