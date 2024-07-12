//https://www.acmicpc.net/problem/12904

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s, t; cin >> s >> t;

    while (1)
    {
        if (t[t.size() - 1] == 'A')
            t.pop_back();
        else
        {
            t.pop_back();
            reverse(t.begin(), t.end());
        }

        if (s.size() == t.size())
        {
            bool flag = s == t;
            cout << flag;

            return 0;
        }
    }
}
