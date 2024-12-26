//https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int len = nums.length, left = 0, min = 999999, sum = 0;
        for(int i=0; i<len; ++i){
            sum += nums[i];
            
            while(sum >= target){
                min = Math.min(min, i - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return min == 999999 ? 0 : min;
    }
}
