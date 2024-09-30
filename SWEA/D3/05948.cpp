#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr[7];
vector<int> vec;

void DFS(int idx, int cnt, int sum) {
    if (cnt == 3) {
        if(find(vec.begin(), vec.end(), sum) == vec.end())
            vec.push_back(sum);
        return;
    }

    for (int i = idx; i < 7; ++i)
        DFS(i + 1, cnt + 1, sum + arr[i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        vec.clear();

        for (int i = 0; i < 7; ++i)
            cin >> arr[i];

        DFS(0, 0, 0);
        sort(vec.begin(), vec.end(), greater<int>());

        cout << '#' << t << ' ' << vec[4] << '\n';
    }
}
