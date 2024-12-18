//https://leetcode.com/problems/find-pivot-index/description/

class Solution {
    public int pivotIndex(int[] nums) {
        int len = nums.length;
        int[] arr = new int[len+2];
        for(int i=1; i<=len; ++i)
            arr[i] = arr[i-1] + nums[i-1];
        
        for(int i=1; i<=len; ++i)
            if(arr[i-1] == arr[len] - arr[i])
                return i-1;
        return -1;
    }
}
