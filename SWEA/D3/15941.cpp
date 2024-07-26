#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cout << '#' << test_case << ' ';
        int n; cin >> n;
        cout << n*n << '\n';
	}
	return 0;
}
