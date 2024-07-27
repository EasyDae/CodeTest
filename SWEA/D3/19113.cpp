#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int n; cin >> n;
        vector<int> vec(n*2), ans(n);

        for (int i = 0; i < 2 * n; ++i)
            cin >> vec[i];

        for (int i = 0, idx = 0; i < 2 * n; ++i) {
            if (!vec[i])
                continue;
            ans[idx++] = vec[i];
            for (int j = i + 1; j < 2 * n; ++j) {
                if (vec[j] * 0.75 == vec[i]){
                    vec[j] = 0;
                    break;
                }
            }
        }

        cout << '#' << test_case << ' ';

        for (auto& x : ans)
            cout << x << ' ';
        cout << '\n';
	}
	return 0;
}
