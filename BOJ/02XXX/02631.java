//https://www.acmicpc.net/problem/2631

import java.io.*;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        int[] dp = new int[n];

        for(int i=0; i<n; ++i)
            arr[i] = Integer.parseInt(br.readLine());

        int ans = 0;
        for(int i=0; i<n; ++i){
            dp[i] = 1;
            for(int j=0; j<i; ++j)
                if(arr[j] < arr[i]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                    ans = Math.max(ans, dp[i]);
                }
        }

        System.out.println(n - ans);
    }
}
