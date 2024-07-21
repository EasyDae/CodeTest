//https://www.acmicpc.net/problem/1759

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l, c;
vector<char> vec, vec2;

bool check()
{
    int cnt = 0;
    for (int i = 0; i < l; ++i)
        if (vec2[i] == 'a' || vec2[i] == 'e' || vec2[i] == 'i' || vec2[i] == 'o' || vec2[i] == 'u')
            cnt++;

    if (cnt >= 1 && l - cnt >= 2)
        return true;
    else
        return false;
}

void func(int idx)
{
    if (vec2.size() == l)
    {
        if (check())
        {
            for (auto& x : vec2)
                cout << x;
            cout << '\n';
        }
        return;
    }

    for (int i = idx; i < c; ++i)
    {
        vec2.push_back(vec[i]);
        func(i + 1);
        vec2.pop_back();
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> l >> c;

    vec = vector<char>(c);
    for (int i = 0; i < c; ++i)
        cin >> vec[i];

    sort(vec.begin(), vec.end());
    func(0);
}
