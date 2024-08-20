#include<iostream>

using namespace std;

char arr[8][8];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 1; i <= 10; ++i) {
        int n, cnt = 0; cin >> n;
        
        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
                cin >> arr[i][j];

        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j <= 8-n; ++j) {
                bool flag = 1;
                for(int k=0; k<n; ++k)
                    if(arr[i][j + k] != arr[i][j + n - k - 1]){
                        flag = 0;
                        break;
                    }
                if (flag) cnt++;
            }
        }

        for (int i = 0; i <= 8 - n; ++i) {
            for (int j = 0; j < 8; ++j) {
                bool flag = 1;
                for(int k=0; k<n; ++k)
                    if(arr[i + k][j] != arr[i + n - k - 1][j]){
                        flag = 0;
                        break;
                    }
                if (flag) cnt++;
            }
        }
        
        cout << '#' << i << ' ' << cnt << '\n';
    }
}
