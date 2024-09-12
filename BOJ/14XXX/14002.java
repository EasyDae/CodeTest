//https://www.acmicpc.net/problem/14002

import java.io.*;
import java.util.*;

public class Main {
    public static int[] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] input = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; ++i)
            input[i] = Integer.parseInt(st.nextToken());

        int[] dp = new int[n];
        int ans = 1;
        dp[0] = 1;
        for(int i=1; i<n; ++i) {
            dp[i] = 1;
            for(int j=0; j<i; ++j){
                if(input[j] < input[i]){
                    dp[i] = Math.max(dp[i], dp[j]+1);
                    ans = Math.max(ans, dp[i]);
                }
            }
        }

        System.out.println(ans);
        int len = ans;
        Stack<Integer> stk = new Stack<>();
        for(int i=n-1; i>=0; --i){
            if(dp[i] == len){
                stk.push(input[i]);
                len--;
            }
        }

        while(!stk.isEmpty())
            System.out.print(stk.pop() + " ");
    }
}
