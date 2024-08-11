#include<iostream>

using namespace std;

string arr[8];

bool check() {
    int cnt = 0;
    
    for (int i = 0; i < 8; ++i) {
        int row_count = 0;
        int col_count = 0;
        for (int j = 0; j < 8; ++j) {
            if (arr[i][j] == 'O') {
                row_count++;
                cnt++;
            }
            if (arr[j][i] == 'O') 
                col_count++;
        }

        if (row_count > 1 || col_count > 1) 
            return false;
    }
    if(cnt != 8)
        return false;
    
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    int test_case;
    
    for (test_case = 1; test_case <= t; ++test_case)
    {
        for (int i = 0; i < 8; ++i)
            cin >> arr[i];

        cout << '#' << test_case << ' ';
        if (check())
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}
