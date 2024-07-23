#include<iostream>
#include<string>
 
using namespace std;
 
int main(int argc, char** argv)
{
    int test_case;
    int T; cin>>T;
 
    for(test_case = 1; test_case <= T; ++test_case)
    {
        string s; cin >> s;
        int len = s.size();
         
        cout << '#' << test_case << ' ';
         
        if(len%2 == 0)
            cout << stoi(s.substr(0, len / 2)) + stoi(s.substr(len / 2, len / 2));
        else{
            string s1 = s.substr(0, len/2+1), s2 = s.substr(len/2, len/2+1);
            if(s1 < s2)
                cout << stoi(s1) + stoi(s.substr(len/2+1, len/2));
            else
                cout << stoi(s2) + stoi(s.substr(0, len/2));
        }
         
        cout << '\n';
    }
    return 0;
}
