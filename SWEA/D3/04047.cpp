#include<iostream>
#include<string.h>
#include<string>

using namespace std;

int arr[4][14];
int ans[4];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        memset(arr, 0, sizeof(arr));

        string s; cin >> s;
        for (int i = 0; i < s.size(); i += 3) {
            switch (s[i]) {
            case 'S':
                arr[0][stoi(s.substr(i + 1, 2))]++;
                break;
                
            case 'D':
                arr[1][stoi(s.substr(i + 1, 2))]++;
                break;

            case 'H':
                arr[2][stoi(s.substr(i + 1, 2))]++;
                break;

            case 'C':
                arr[3][stoi(s.substr(i + 1, 2))]++;
                break;
            }
        }

        bool flag = 1;
        for (int i = 0; i < 4; ++i) {
            int cnt = 0;
            for (int j = 0; j < 14; ++j) {
                if (arr[i][j] == 1)
                    cnt++;
                else if (arr[i][j] > 1) {
                    cout << '#' << t << ' ' << "ERROR\n";
                    flag = 0;
                    break;
                }
            }
            if (!flag)
                break;

            ans[i] = 13 - cnt;
        }
        if (flag) {
        	cout << '#' << t << ' ';
        	for (int i = 0; i < 4; ++i)
            	cout << ans[i] << ' ';
        	cout << '\n';
        }
    }
}
