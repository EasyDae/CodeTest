//https://www.acmicpc.net/problem/9339

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--)
    {
        int passcnt = 0, max = 2147483647, idx = 0;

        int k; cin >> k;
        vector<int> vec(k);

        for (int i = 0; i < k; ++i)
            cin >> vec[i];

        int n; cin >> n;
        for (int i = 0; i < n; ++i)
        {
            int num, hour, min;
            cin >> num >> hour >> min;
            for (int j = 0; j < k; ++j)
            {
                if (num == vec[j])
                {
                    int score = hour * 60 + min;
                    if (score >= 0 && score <= 360)
                    {
                        if (max >= score)
                        {
                            max = score;
                            idx = j;
                        }
                        passcnt++;
                    }
                }
            }
        }

        cout << vec[idx] << ' ' << passcnt << '\n';
    }
}
