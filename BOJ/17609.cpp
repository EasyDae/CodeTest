//https://www.acmicpc.net/problem/17609

#include<iostream>

using namespace std;

int checkpalin(string str, int left, int right, int cnt) {
    while (left < right) 
    {
        if (str[left] != str[right]) 
        {
            if (!cnt) 
            {
                if (!checkpalin(str, left + 1, right, cnt + 1) || !checkpalin(str, left, right - 1, cnt + 1))
                    return 1;
                return 2;
            }
            else
                return 2;
        }
        else 
        {
            left++;
            right--;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    for(int i=0; i<t; ++i){
        string s; cin >> s;
        cout << checkpalin(s, 0, s.size()-1, 0) << '\n';
    }
    return 0;
}
