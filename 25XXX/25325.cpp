//https://www.acmicpc.net/problem/25325

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> m;
pair<int, string> pr[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    string s;

    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        m.insert({ s,i });
        pr[i].second = s;
    }

    while (cin >> s)
        pr[m[s]].first--;

    sort(pr, pr + n);

    for (int i = 0; i < n; ++i)
        cout << pr[i].second << ' ' << -pr[i].first << '\n';
}
