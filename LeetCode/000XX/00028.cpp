//https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int lenA = haystack.size(), lenB = needle.size();
        for(int i=0; i<=lenA-lenB; ++i){
            bool flag = false;
            if(haystack[i] == needle[0]){
                for(int j=1; j<lenB; ++j){
                    if(haystack[i+j] != needle[j]){
                        flag = true;
                        break;
                    }
                }
                if(!flag)
                    return i;
            }
        }
        return -1;
    }
};
