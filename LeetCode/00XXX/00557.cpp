//https://leetcode.com/problems/reverse-words-in-a-string-iii/

class Solution {
public:
    string reverseWords(string s) {
        string tmp, ans;
        for(int i=0; i<s.size(); ++i){
            if(s[i] != ' ')
                tmp += s[i];
            else{
                if(tmp != ""){
                    reverse(tmp.begin(), tmp.end());
                    ans += tmp;
                    ans += ' ';
                    tmp = "";
                }
            }
        }
        reverse(tmp.begin(), tmp.end());
        ans += tmp;
        return ans;
    }
};
