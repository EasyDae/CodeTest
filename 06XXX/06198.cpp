//https://www.acmicpc.net/problem/6198

#include <iostream>
#include <stack>

using namespace std;

int n, arr[80001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    long long ans = 0;
    stack<int> st;
    for (int i = 0; i < n; ++i){
        cin >> arr[i];

        if (st.empty()) {
            st.push(arr[i]);
            continue;
        }

        while (!st.empty() && st.top() <= arr[i])
            st.pop();

        ans += st.size();
        st.push(arr[i]);
    }

    cout << ans;
}
