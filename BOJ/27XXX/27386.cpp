//https://www.acmicpc.net/problem/27386

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1, s2; cin >> s1 >> s2;
    vector<char> vec;

    for (auto& x : s1)
        vec.push_back(x);

    for (auto& x : s2)
        vec.push_back(x);

    sort(vec.begin(), vec.end());

    for (auto& x : vec)
        cout << x;
}
