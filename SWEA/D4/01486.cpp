#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

int n, b, diff = 99999;
vector<int> vec;
bool check[20];

void DFS(int idx, int sum) {
    if (sum >= b) {
        diff = min(diff, sum - b);
        return;
    }

    for (int i = idx; i < n; ++i) {
        if (check[i])
            continue;
        check[i] = 1;
        DFS(i, sum + vec[i]);
        check[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    int test_case;

    for (test_case = 1; test_case <= t; ++test_case)
    {
        diff = 99999;
        memset(check, 0, sizeof(check));
        cin >> n >> b;
        vec = vector<int>(n);

        for (int i = 0; i < n; ++i)
            cin >> vec[i];

        DFS(0, 0);
        cout << '#' << test_case << ' ' << diff << '\n';
    }
    return 0;
}
