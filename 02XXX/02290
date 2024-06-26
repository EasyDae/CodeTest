//https://www.acmicpc.net/problem/2290

#include <iostream>

using namespace std;

int s;
string n;
int arr[10][7] = {
    {1,1,1,0,1,1,1},
    {0,0,1,0,0,1,0},
    {1,0,1,1,1,0,1},
    {1,0,1,1,0,1,1},
    {0,1,1,1,0,1,0},
    {1,1,0,1,0,1,1},
    {1,1,0,1,1,1,1},
    {1,0,1,0,0,1,0},
    {1,1,1,1,1,1,1},
    {1,1,1,1,0,1,1}
};

void func(char c, int idx)
{
    int num = c - '0';

    if (!(idx % 3))
    {
        cout << ' ';
        if (arr[num][idx])
            for (int i = 0; i < s; ++i)
                cout << '-';
        else
            for (int i = 0; i < s; ++i)
                cout << ' ';

        cout << "  ";
    }
    else
    {
        if (arr[num][idx])
            cout << '|';
        else
            cout << ' ';

        if (idx % 3 == 1)
            for (int i = 0; i < s; ++i)
                cout << ' ';
        else
            cout << ' ';
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s >> n;

    for (int i = 0; i < n.size(); ++i)
        func(n[i], 0);
    cout << '\n';

    for (int i = 0; i < s; ++i)
    {
        for (int j = 0; j < n.size(); ++j)
            func(n[j], 1), func(n[j], 2);
        cout << '\n';
    }

    for (int i = 0; i < n.size(); ++i)
        func(n[i], 3);
    cout << '\n';

    for (int i = 0; i < s; ++i)
    {
        for (int j = 0; j < n.size(); ++j)
            func(n[j], 4), func(n[j], 5);
        cout << '\n';
    }

    for (int i = 0; i < n.size(); ++i)
        func(n[i], 6);
    cout << '\n';
}
