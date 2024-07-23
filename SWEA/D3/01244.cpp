#include<iostream>
#include<algorithm>
#include<string>
 
using namespace std;
 
int Maxcnt, ans;
string s;
 
void DFS(int idx, int cnt){
    if(cnt == Maxcnt){
        ans = max(ans, stoi(s));
        return;
    }
     
    for(int i=idx; i<s.size()-1; ++i){
        for(int j=i+1; j<s.size(); ++j){
            if(s[i] <= s[j]){
                swap(s[i], s[j]);
                DFS(i, cnt+1);
                swap(s[i], s[j]);
            }
             
            if(i == s.size()-2 && j == s.size()-1){
                swap(s[i], s[j]);
                DFS(i, cnt+1);
                swap(s[i], s[j]);
            }
        }
    }
}
 
int main(int argc, char** argv)
{
    int test_case;
    int T; cin>>T;
     
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> s >> Maxcnt;
        ans = 0;
        DFS(0, 0);
         
        cout << '#' << test_case << ' ' << ans << '\n';
    }
    return 0;
}
