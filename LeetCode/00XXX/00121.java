class Solution {
    public int maxProfit(int[] prices) {
        int ans = 0, cur = 0;
        for(int i=prices.length-1; i>=0; --i){
            if(cur < prices[i])
                cur = prices[i];
            else
                ans = Math.max(ans, cur - prices[i]);
        }
        return ans;
    }
}
