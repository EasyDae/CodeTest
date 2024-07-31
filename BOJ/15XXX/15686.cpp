//https://www.acmicpc.net/problem/15686

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, Min = 2147483647;
int arr[51][51];
bool check[13];
vector<pair<int, int>> chicken, house, Select;

int Dist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void calcDist() {
    int tmp = 0;
    for (int i = 0; i < house.size(); ++i) {
        int MIN = 2147483647;
        for (int j = 0; j < Select.size(); ++j) {
            MIN = min(MIN, Dist(house[i], Select[j]));
        }
        tmp += MIN;
    }
    Min = min(tmp, Min);
}

void DFS(int idx, int cnt) {
    if (cnt == m) {
        calcDist();
    }

    for (int i = idx; i < chicken.size(); ++i) {
        if (check[i])
            continue;

        check[i] = 1;
        Select.push_back(chicken[i]);
        DFS(i, cnt + 1);
        Select.pop_back();
        check[i] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
                house.push_back({ i,j });
            if (arr[i][j] == 2)
                chicken.push_back({ i,j });
        }
    }

    DFS(0, 0);
    cout << Min;
}
