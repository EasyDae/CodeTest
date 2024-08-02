#include<iostream>
#include<stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int test_case = 1; test_case <= 10; ++test_case)
    {
        cout << '#' << test_case << ' ';
        int n; cin >> n;
        string s; cin >> s;
        stack<char> st;

        bool flag = 1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{' || s[i] == '<')
                st.push(s[i]);
            else {
				if(st.empty()){
                    flag = 0;
                    break;
                }

                char top = st.top();
                if ((top == '(' && s[i] == ')') ||
                    (top == '[' && s[i] == ']') ||
                    (top == '{' && s[i] == '}') ||
                    (top == '<' && s[i] == '>'))
                    st.pop();
                else {
                    flag = false;
                    break;
                }
            }
        }

        if (!st.empty())
            flag = false;

        if (flag)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
    return 0;
}
