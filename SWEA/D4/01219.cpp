#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>

using namespace std;

int arr[100][2];

int dfs(int start,int next){
    if (arr[start][next] == 99)
        return 1;
    if (arr[start][next] == 0) 
        return 0;

    if (dfs(arr[start][next], 0)) 
        return 1;
    return dfs(arr[start][next], 1);
}

int main() {
    for (int t = 1; t <= 10; t++) {
        int s, n; cin >> s >> n;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            if (arr[a][0] != 0) {
                arr[a][1] = b;
                continue;
            }
            arr[a][0] = b;
        }
        cout << "#" << s << ' ' << dfs(0, 0) << '\n';
        memset(arr, 0, sizeof(arr));
    }
    return 0;
}
