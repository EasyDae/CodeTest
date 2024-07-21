#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;

	for(test_case = 1; test_case <= 10; ++test_case)
	{
        int n; cin >> n;
        vector<int> vec(n);
        
        for(int i=0; i<n; ++i)
            cin >> vec[i];
        
        if(n==4)
        {
            cout << '#' << test_case << ' ' << 0 << '\n';
            continue;
        }
        
        int cnt = 0;
        for(int i=2; i<n-2; ++i)
        {
            int MaxH = max(vec[i-2], max(vec[i-1], max(vec[i+1], vec[i+2])));
            if(vec[i] - MaxH > 0)
                cnt+=vec[i]-MaxH;
        }
        
        cout << '#' << test_case << ' ' << cnt << '\n';
	}
	return 0;
}
