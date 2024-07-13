//https://www.acmicpc.net/problem/12919

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string s, t;
bool flag;

void func(string T)
{
    if (T.size() == s.size())
    {
        if (T == s)
            flag = 1;
        return;
    }

    if(T[T.size()-1] == 'A')
    {
        string tmp = T;
        tmp.pop_back();
        func(tmp);
    }
    if (T[0] == 'B')
    {
        string tmp = T;
        reverse(tmp.begin(), tmp.end());
        tmp.pop_back();
        func(tmp);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s >> t;

    func(t);

    cout << flag;
}
