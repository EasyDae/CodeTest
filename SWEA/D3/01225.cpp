#include<iostream>
#include<deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;

    for (test_case = 1; test_case <= 10; ++test_case)
    {
        int T; cin >> T;
        deque<int> dq;
        for (int i = 0; i < 8; ++i) {
            int n; cin >> n;
            dq.push_back(n);
        }

        int num = 1;
        while (1) {
            int tmp = dq.front();
            dq.pop_front();
            tmp -= num;
            if (tmp <= 0) {
                tmp = 0;
                dq.push_back(tmp);
                break;
            }
            else {
                dq.push_back(tmp);
                num = num%5 + 1;
            }
        }

        cout << '#' << test_case << ' ';
        for (auto& x : dq)
            cout << x << ' ';
    }
    return 0;
}
