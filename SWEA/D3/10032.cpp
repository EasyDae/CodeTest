#include<iostream>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     
    int T; cin >> T;
    for(int t=1; t<=T; ++t){
        int a,b; cin >> a >> b;
        int tmp = a % b != 0 ? 1 : 0;
        cout << '#' << t << ' ' << tmp << '\n';
    }
}
