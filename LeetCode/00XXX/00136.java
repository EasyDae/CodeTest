//https://leetcode.com/problems/single-number/

class Solution {
    public int singleNumber(int[] nums) {
        int[] arr = new int[60001];
        int min = 40000, max = -40000;
        for(int a : nums){
            min = Math.min(min, a);
            max = Math.max(max, a);
            arr[a+30000]++;
        }
        for(int i = min+30000; i <= max+30000; ++i)
            if(arr[i]==1)
                return i-30000;
        return 0;
    }
}
