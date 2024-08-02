//https://www.acmicpc.net/problem/2504

#include<iostream>
#include<stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<char> st;
    string s; cin >> s;

    int ans = 0, tmp = 1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            tmp *= 2;
            st.push(s[i]);
        }
        else if (s[i] == '[') {
            tmp *= 3;
            st.push(s[i]);
        }
        else if (s[i] == ')') {
            if (st.empty() || st.top() != '(') {
                cout << 0;
                return 0;
            }
            if (s[i - 1] == '(') {
                ans += tmp;
                tmp /= 2;
                st.pop();
            }
            else {
                tmp /= 2;
                st.pop();
            }
        }
        else if (s[i] == ']') {
            if (st.empty() || st.top() != '[') {
                cout << 0;
                return 0;
            }
            if (s[i - 1] == '[') {
                ans += tmp;
                tmp /= 3;
                st.pop();
            }
            else {
                tmp /= 3;
                st.pop();
            }
        }
    }

    if (!st.empty())
        cout << 0;
    else
        cout << ans;
}
