#include<iostream>
#include<string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        string s1, s2; cin >> s1 >> s2;
        int cur = 0, pro = 0, ans = 0;

        cur = (stoi(s1.substr(0, 2)) * 3600) + (stoi(s1.substr(3, 2)) * 60) + stoi(s1.substr(6, 2));
        pro = (stoi(s2.substr(0, 2)) * 3600) + (stoi(s2.substr(3, 2)) * 60) + stoi(s2.substr(6, 2));

        ans = pro - cur;

        if (ans > 0){
            cout << "#" << t << " ";
            if (ans / 3600 < 10)
                cout << "0" << ans / 3600 << ":";
            else
                cout << ans / 3600 << ":";
            if (ans % 3600 / 60 < 10)
                cout << "0" << ans % 3600 / 60 << ":";
            else
                cout << ans % 3600 / 60 << ":";
            if (ans % 60 < 10)
                cout << "0" << ans % 60 << endl;
            else
                cout << ans % 60 << endl;
        }
        else{
            ans += (3600 * 24);
            cout << "#" << t << " ";
            if (ans / 3600 < 10)
                cout << "0" << ans / 3600 << ":";
            else
                cout << ans / 3600 << ":";
            if (ans % 3600 / 60 < 10)
                cout << "0" << ans % 3600 / 60 << ":";
            else
                cout << ans % 3600 / 60 << ":";
            if (ans % 60 < 10)
                cout << "0" << ans % 60 << endl;
            else
                cout << ans % 60 << endl;
        }
    }
}
