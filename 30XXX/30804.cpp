//https://www.acmicpc.net/problem/30804

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, cnt, arr[10], ans;
queue<int> q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    while (n--){
        int s; cin >> s;
        q.push(s);

        if (arr[s]++ == 0)
            cnt++;

        while (cnt > 2) {
            s = q.front();
            q.pop();

            if (--arr[s] == 0)
                cnt--;
        }

        ans = max(ans, static_cast<int>(q.size()));
    }

    cout << ans;
}
