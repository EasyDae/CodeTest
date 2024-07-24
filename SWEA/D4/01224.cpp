#include<iostream>
#include<string>
#include<stack>

using namespace std;

int len;
string str;

int postfix() {
    stack<char> st;
    stack<int> calc;

    string tmp;

    for (int i = 0; i < len; ++i) {
        if (str[i] >= '0' && str[i] <= '9')
            tmp += str[i];
        else {
            if (str[i] == '(') 
                st.push(str[i]);
            else if (str[i] == '+') {
                if (st.empty()) {
                    st.push(str[i]); 
                    continue;
                }
                if (st.top() == '+' || st.top() == '*') {
                    while (st.top() == '+' || st.top() == '*') {
                        tmp += st.top();
                        st.pop();
                        if (st.empty()) break;
                    }
                }
                st.push(str[i]);
            }
            else if (str[i] == '*') {
                if (st.empty()) {
                    st.push(str[i]); 
                    continue;
                }
                if (st.top() == '*') {
                    while (st.top() == '*') {
                        tmp += st.top();
                        st.pop();
                        if (st.empty()) break;
                    }
                }
                st.push(str[i]);
            }
            else if (str[i] == ')') {
                while (st.top() != '(') {
                    tmp += st.top();
                    st.pop();
                    if (st.empty()) break;
                }
                st.pop();
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
            if(tmp[i] == '+'){
            	int a = calc.top();
            	calc.pop();
            	int b = calc.top();
            	calc.pop();
            	calc.push(a + b);
            }
            else if(tmp[i] == '*'){
                int a = calc.top();
                calc.pop();
                int b = calc.top();
                calc.pop();
                calc.push(a*b);
            }
        }
    }

    int ans = calc.top();
    return ans;
}

int main(int argc, char** argv)
{
	int test_case;
	for(test_case = 1; test_case <= 10; ++test_case)
	{
        cin >> len >> str;
        cout << '#' << test_case << ' ' << postfix() << '\n';
	}
	return 0;
}
