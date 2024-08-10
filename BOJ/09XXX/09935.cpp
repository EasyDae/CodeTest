//https://www.acmicpc.net/problem/9935

#include<iostream>
#include<string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s, boom, tmp; cin >> s >> boom;
    for (int i = 0; i < s.size(); ++i) {
        tmp += s[i];
        if (tmp.size() >= boom.size()) {
            bool flag = 1;
            for (int j = 0; j < boom.size(); ++j) {
                if (tmp[tmp.size() - boom.size() + j] != boom[j]) {
                    flag = 0;
                    break;
                }
            }

            if (flag)
                tmp.erase(tmp.end() - boom.size(), tmp.end());
        }
    }

    if (tmp.empty())
        cout << "FRULA";
    else
        cout << tmp;
}
