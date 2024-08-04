#include<iostream>
#include<string>
#include<queue>

using namespace std;

int arr[101][101];
int Min = 2147483647, ans = -1;

int Ladder(int idx) 
{
    int cnt = 1;
    int x = 0, y = idx;
    char dir = 'D';

    while (1) 
    {
        if (dir == 'D') 
        {
            x++;
            cnt++;
            while (1) 
            {
                if (x == 99)
                    return cnt;

                if (y < 99) 
                {
                    if (arr[x][y + 1])
                    {
                        dir = 'R';
                        break;
                    }
                }

                if (y > 0)
                {
                    if (arr[x][y - 1] == 1)
                    {
                        dir = 'L';
                        break;
                    }
                }

                x++;
                cnt++;
            }
        }
        else if (dir == 'R')
        {
            y++;
            cnt++;
            while (1)
            {
                if (x < 99)
                {
                    if (arr[x + 1][y] == 1)
                    {
                        dir = 'D';
                        break;
                    }
                }
                y++;
                cnt++;
            }
        }
        else if (dir == 'L')
        {
            y--;
            cnt++;
            while (1)
            {
                if (x < 99)
                {
                    if (arr[x + 1][y] == 1)
                    {
                        dir = 'D';
                        break;
                    }
                }
                y--;
                cnt++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;

    for (test_case = 1; test_case <= 10; ++test_case)
    {
        int n; cin >> n;
        cout << '#' << n << ' ';

        Min = 2147483647, ans = -1;

        for (int i = 0; i < 100; ++i)
            for (int j = 0; j < 100; ++j)
                cin >> arr[i][j];

        for (int i = 0; i < 100; ++i) 
        {
            if (arr[0][i]) 
            {
                int tmp = Ladder(i);
                if (Min > tmp) 
                {
                    Min = tmp;
                    ans = i;
                }
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
