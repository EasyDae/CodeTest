#include<iostream>
#include<string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int t = 1; t <= 10; ++t) {
        int T; cin >> T;
        string target; cin >> target;
        string str; cin >> str;
        int cnt = 0, len = target.size();
        
        for (int i = 0; i < str.size(); ++i)
            if(str.substr(i, len) == target){
                cnt++;
                i += len;
            }

        cout << '#' << T << ' ' << cnt << '\n';
    }
}
