//https://www.acmicpc.net/problem/2493

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<pair<int, int>> st;
    int n; cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        int height; cin >> height;
        while (!st.empty())
        {
            if (height < st.top().first)
            {
                cout << st.top().second << ' ';
                break;
            }
            else
                st.pop();
        }

        if (st.empty())
            cout << 0 << ' ';

        st.push({ height, i });
    }
}
