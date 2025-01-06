class Solution {
public:
    bool isPalindrome(int x) {
        string s1 = to_string(x);
        string s2 = s1;
        reverse(s1.begin(), s1.end());
        return s2 == s1 ? true : false;
    }
};
