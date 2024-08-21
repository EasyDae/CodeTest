#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(6);
    cout << fixed;

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int N;
        cin >> N;
        vector<vector<double>> vec(N, vector<double>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                cin >> vec[i][j];
                vec[i][j] /= 100;
            }

        vector<double> dp(1 << N, 0);
        dp[0] = 1.0;

        for (int mask = 0; mask < (1 << N); mask++)
        {
            int x = __builtin_popcount(mask);
            for (int j = 0; j < N; j++)
                if (!(mask & (1 << j)))
                    dp[mask | (1 << j)] = max(dp[mask | (1 << j)], dp[mask] * vec[x][j]);
        }

        double result = dp[(1 << N) - 1] * 100;
        cout << "#" << t << " " << result << '\n';
    }

    return 0;
}
