//https://www.acmicpc.net/problem/2166

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> vec;

long double func(int i, int j){
    long double a = vec[0].first, b = vec[0].second;
    long double c = vec[i].first, d = vec[i].second;
    long double e = vec[j].first, f = vec[j].second;

    return (a * d + c * f + e * b - c * b - e * d - a * f) / 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;


    for (int i = 0; i < n; ++i){
        int x, y; cin >> x >> y;
        vec.push_back({ x,y });
    }

    long double ans = 0;

    for (int i = 1; i < n - 1; ++i)
        ans += func(i, i + 1);

    cout << fixed;
    cout.precision(1);
    cout << abs(ans);
}
