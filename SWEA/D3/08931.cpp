#include<iostream>
#include<stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int k; cin >> k;
        stack<int> st;
        for (int i = 0; i < k; ++i) {
            int input; cin >> input;
            if (input == 0)
                st.pop();
            else
                st.push(input);
        }

        int ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        cout << '#' << t << ' ' << ans << '\n';
    }
}
