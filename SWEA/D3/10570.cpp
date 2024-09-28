#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int ans = 0;
        int a, b; cin >> a >> b;

        for (int i = a; i <= b; ++i) {
            int tmp = sqrt(i);
            if (tmp * tmp == i) {
                string s1 = to_string(i);
                string s2 = s1;
                string s3 = to_string(tmp);
                string s4 = s3;
                reverse(s2.begin(), s2.end());
                reverse(s4.begin(), s4.end());

                if (s1 == s2 && s3 == s4)
                    ans++;
            }
        }

        cout << "#" << t << " " << ans << endl;
    }
}
