//https://leetcode.com/problems/rotate-array/

class Solution {
    public void rotate(int[] nums, int k) {
        int len = nums.length;
        k %= len;
        int[] arr = new int[k];
        for(int i=0; i<k; ++i)
            arr[i] = nums[len-k+i];
        for(int i=len-k-1; i>=0; --i)
            nums[i+k] = nums[i];
        for(int i=0; i<k; ++i)
            nums[i] = arr[i];
    }
}
