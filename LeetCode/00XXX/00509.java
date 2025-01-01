//https://leetcode.com/problems/fibonacci-number/

class Solution {
    public int fib(int n) {
        int[] arr = new int[n+1];
        return fibo(arr, n); 
    }
    int fibo(int[] arr, int val){
        if(val <=1)
            return val;
        if(arr[val] != 0)
            return arr[val];
        arr[val] = fibo(arr, val-1) + fibo(arr, val-2);
        return arr[val];
    }
}
