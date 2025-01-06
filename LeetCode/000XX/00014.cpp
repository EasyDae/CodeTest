class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for(int i=1; i<strs.size(); ++i){
            string tmp;
            for(int j=0; j<ans.size(); ++j){
                if(j==0 && strs[i][0] != ans[0])
                    return "";
                if(strs[i][j] != ans[j])
                    break;
                tmp += strs[i][j];
            }
            ans = tmp;
        }
        return ans;
    }
};
