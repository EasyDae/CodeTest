//https://www.acmicpc.net/problem/14891

#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

string s[4];

void rotate(int idx, int dir) {
    if (dir == 1)
        s[idx] = s[idx][7] + s[idx].substr(0, 7);
    else
        s[idx] = s[idx].substr(1, 7) + s[idx][0];
}

void leftcheck(int idx, int dir) {
    if (idx <= 0)
        return;
    if (s[idx][6] != s[idx - 1][2]) {
        leftcheck(idx - 1, dir * -1);
        rotate(idx - 1, dir * -1);
    }
}

void rightcheck(int idx, int dir) {
    if (idx >= 3)
        return;
    if(s[idx][2] != s[idx + 1][6]){
        rightcheck(idx + 1, dir * -1);
        rotate(idx + 1, dir * -1);
    }
}

void check(int idx, int dir) {
    leftcheck(idx, dir);
    rightcheck(idx, dir);
    rotate(idx, dir);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 4; ++i)
        cin >> s[i];

    int k; cin >> k;
    while (k--) {
        int idx, dir; cin >> idx >> dir;
        check(idx - 1, dir);
    }

    int ans = 0;
    for (int i = 0; i < 4; ++i)
        if (s[i][0] == '1')
            ans += pow(2, i);

    cout << ans;
}
