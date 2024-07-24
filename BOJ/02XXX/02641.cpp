//https://www.acmicpc.net/problem/2641

#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string arr[101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int len, cnt = 0; cin >> len;
    string tg1, tg2;
    for (int i = 0; i < len; ++i) {
        char c; cin >> c;
        tg1 += c;
        tg2 += (c + 1) % 4 + 1 + '0';
    }

    reverse(tg2.begin(), tg2.end());

    int n; cin >> n;
    while (n--) {
        string s;
        for (int i = 0; i < len; ++i) {
            char c; cin >> c;
            s += c;
        }

        string tmp = s;
        for (int i = 0; i < len; ++i) {
            if (tmp == tg1 || tmp == tg2) {
                arr[cnt] = s;
                cnt++;
                break;
            }
            tmp = tmp.substr(1, tmp.size()) + tmp[0];
        }
    }

    cout << cnt << '\n';
    for (int i = 0; i < cnt; ++i) {
        for (auto& x : arr[i])
            cout << x << ' ';
        cout << '\n';
    }
}
