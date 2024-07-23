#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T; cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int a,b,c, cnt = 0; cin >> a >> b >> c;
        if(b<2 || c<3){
            cout << '#' << test_case << ' ' << -1 << '\n';
            continue;
        }
        if(a<b && b<c){
            cout << '#' << test_case << ' ' << 0 << '\n';
            continue;
        }
        
        if(c<=b){
            cnt+=b-c+1;
            b -= (b-c+1);
        }
        
        if(b<=a){
            cnt+=a-b+1;
            a-=(a-b+1);
        }
        
        cout << '#' << test_case << ' ' << cnt << '\n';
	}
	return 0;
}
