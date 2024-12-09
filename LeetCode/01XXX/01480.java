https://leetcode.com/problems/running-sum-of-1d-array/

class Solution {
    public int[] runningSum(int[] nums) {
        int[] arr = new int[nums.length];
        int prev = 0;
        for(int i=0; i<nums.length; ++i){
            arr[i] = nums[i] + prev;
            prev += nums[i];
        }
        return arr;
    }
}
