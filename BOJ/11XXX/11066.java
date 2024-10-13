//https://www.acmicpc.net/problem/11066

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());
        for(int t=0; t<T; ++t){
            int K = Integer.parseInt(br.readLine());
            int[] arr = new int[K +1];
            int[][] dp = new int[K +1][K +1];

            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int i = 1; i<= K; ++i)
                arr[i] = Integer.parseInt(st.nextToken()) + arr[i-1];

            for(int i = 1; i < K; ++i){
                for(int j = 1; i+j <= K; ++j){
                    int end = i + j;
                    dp[j][end] = Integer.MAX_VALUE;

                    for(int k=j; k<end; ++k)
                        dp[j][end] = Math.min(dp[j][end], dp[j][k] + dp[k+1][end] + arr[end] - arr[j-1]);
                }
            }

            sb.append(dp[1][K]).append('\n');
        }
        System.out.println(sb);
    }
}
