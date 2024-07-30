#include<iostream>
#include<string>
#include<stack>

using namespace std;

int postfix(string str, int len) {
    stack<int> calc;
    stack<char> st;
    string tmp;

    for (int i = 0; i < len; ++i) {
        if (isdigit(str[i]))
            tmp += str[i];
        else {
            if (st.empty())
                st.push(str[i]);
            else
                tmp += st.top();
        }
    }

    tmp += st.top();
    st.pop();

    for (int i = 0; i < tmp.size(); ++i) {
        if (isdigit(tmp[i]))
            calc.push(tmp[i] - '0');
        else {
            int n1 = calc.top();
            calc.pop();
            int n2 = calc.top();
            calc.pop();
            calc.push(n1 + n2);
        }
    }

    return calc.top();
}

int main(){
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
