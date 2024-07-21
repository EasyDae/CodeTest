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
        vector<long long> vec(n);
         
        for(int i=0; i<n; ++i)
            cin >> vec[i];
         
        long long sum = 0, Max = vec[n-1];
         
        for(int i=n-2; i>=0; --i)
        {
            if(vec[i] < Max)
                sum += Max - vec[i];
            else
                Max = vec[i];
        }
         
        cout << '#' << test_case << ' ' << sum << '\n';
    }
    return 0;
}
