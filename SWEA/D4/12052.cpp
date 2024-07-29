#include<iostream>

using namespace std;

int n, m;
char arr[51][51];

void func(int x, int y) {
    if (arr[x + 1][y + 1] == '#' && arr[x][y + 1] == '#' && arr[x + 1][y] == '#') {
        arr[x][y] = '.';
        arr[x + 1][y] = '.';
        arr[x][y + 1] = '.';
        arr[x + 1][y + 1] = '.';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> arr[i][j];

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (arr[i][j] == '#')
                    func(i, j);

        bool flag = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (arr[i][j] == '#') {
                    flag = 0;
                    break;
                }
                if (!flag)
                    break;
            }
        }
        
        cout << '#' << test_case << ' ';

        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
