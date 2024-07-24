#include<iostream>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
  cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        string s1, s2; cin >> s1 >> s2;
        while(s1.size() < s2.size()){
            if(s2.back() == 'X')
                s2.pop_back();
            else{
                s2.pop_back();
                reverse(s2.begin(), s2.end());
            }
        }
        cout << '#' << test_case << ' ';
        
        if(s1 == s2)
            cout << "Yes\n";
        else
            cout << "No\n";
	}
	return 0;
}
