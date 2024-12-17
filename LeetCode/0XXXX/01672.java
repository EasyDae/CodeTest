//https://leetcode.com/problems/richest-customer-wealth/

class Solution {
    public int maximumWealth(int[][] accounts) {
        int Max = 0;
        for(int i=0; i<accounts.length; ++i){
            int tmp = 0;
            for(int j=0; j<accounts[i].length; ++j)
                tmp += accounts[i][j];
            Max = Math.max(Max, tmp);
        }
        return Max;
    }
}
