//https://leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    string reverseWords(string s) {
        vector<string> vec;
        for(int i=0; i<s.size(); ++i){
            string tmp;
            if(s[i] != ' '){
                while(i < s.size() && s[i] != ' ')
                    tmp += s[i++];
                vec.push_back(tmp);
            }
        }
        string ans;
        for(int i=vec.size()-1; i>=0; --i){
            ans += vec[i];
            if(i!=0)
                ans += ' ';
        }
        return ans;
    }
};
