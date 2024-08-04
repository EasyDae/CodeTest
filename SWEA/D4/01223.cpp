#include<iostream>
#include<string>
#include<stack>

using namespace std;

int postfix(string str, int len) {
    stack<char> st;
    stack<int> calc;
    string tmp;

    for (int i = 0; i < len; ++i) {
        if (isdigit(str[i]))
            tmp += str[i];
        else {
            if (str[i] == '+') {
                while (!st.empty() && (st.top() == '+' || st.top() == '*')) {
                    tmp += st.top();
                    st.pop();
                }
                st.push(str[i]);
            }
            else if (str[i] == '*') {
                while (!st.empty() && st.top() == '*') {
                    tmp += st.top();
                    st.pop();
                }
                st.push(str[i]);
            }
        }
    }

    while (!st.empty()) {
        tmp += st.top();
        st.pop();
    }
    
    for (int i = 0; i < tmp.size(); ++i) {
        if (isdigit(tmp[i]))
            calc.push(tmp[i] - '0');
        else {
            int b = calc.top(); calc.pop();
            int a = calc.top(); calc.pop();
            if (tmp[i] == '+')
                calc.push(a + b);
            else if (tmp[i] == '*')
                calc.push(a * b);
        }
    }

    int ans = calc.top();
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;

    for (test_case = 1; test_case <= 10; ++test_case)
    {
        int n; cin >> n;
        string s; cin >> s;

        cout << '#' << test_case << ' ' << postfix(s, n) << '\n';
    }
    return 0;
}
