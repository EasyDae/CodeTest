#include<iostream>

using namespace std;

int gcd(int a, int b){
	while(b!=0){
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b){
    return (a * b) / gcd(a,b);
}

int main(int argc, char** argv)
{
	int test_case;
	int T; cin>>T;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cout << '#' << test_case << ' ';
        string s1, s2; cin >> s1 >> s2;
        
        if(s1 == s2)
            cout << "yes" << '\n';
        else{
            int len1 = s1.size(), len2 = s2.size();
        	int LCM = lcm(len1, len2);

       		string str1, str2;
        	for (int i = 0; i < LCM / len1; ++i)
            	str1 += s1;

        	for (int i = 0; i < LCM / len2; ++i)
            	str2 += s2;

        	if (str1 == str2)
            	cout << "yes" << '\n';
        	else
            	cout << "no" << '\n';
        }
	}
	return 0;
}
