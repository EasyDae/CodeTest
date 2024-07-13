//https://www.acmicpc.net/problem/7599

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1)
    {
        string s; int f;
        cin >> s >> f;

        if (s == "#")
            return 0;

        cout << s << ' ' << "Library\n";

        int c; cin >> c;
        for (int i = 1; i <= c; ++i)
        {
            int w; string str;
            cin >> w >> str;

            cout << "Book " << i << ' ';

            if (w >= 2 + str.size() * f)
                cout << "horizontal\n";
            else
                cout << "vertical\n";
        }
    }
}
