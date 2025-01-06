class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        bool flag = false;
        int len = max(a.size(), b.size());
        string ans;
        for(int i=0; i<len; ++i){
            int sum = flag;
            sum += (i < a.size()) ? (a[i] - '0') : 0;
            sum += (i < b.size()) ? (b[i] - '0') : 0;
            ans += (sum % 2 + '0');
            flag = sum > 1;
        }
        
        if(flag) ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
