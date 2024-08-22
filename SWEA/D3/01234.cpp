#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int t = 1; t <= 10; ++t) {
        int n; cin >> n;

        stack<char> st;
        for (int i = 0; i < n; ++i) {
            char c; cin >> c;
            if (!st.empty() && st.top() == c)
                st.pop();
            else
                st.push(c);
        }

        string tmp;
        while (!st.empty()) {
            tmp += st.top();
            st.pop();
        }
        
        reverse(tmp.begin(), tmp.end());

        cout << '#' << t << ' ' << tmp << '\n';
    }
}
