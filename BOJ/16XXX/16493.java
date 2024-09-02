//https://www.acmicpc.net/problem/16493

import java.io.*;
import java.util.*;

public class Main {
	public static int n, m;
	public static int[][] dp;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		int [][] input = new int[m + 1][2];
        dp = new int[m + 1][n + 1];

        for(int i=1; i<=m; ++i) {
        	st = new StringTokenizer(br.readLine());
        	int a = Integer.parseInt(st.nextToken());
        	int b = Integer.parseInt(st.nextToken());
        	
        	input[i][0] = a;
        	input[i][1] = b;
        }
        
        for(int i=1; i<=m; ++i) {
        	int a = input[i][0];
        	int b = input[i][1];
        	
        	for(int j=1; j<=n; ++j) {
        		dp[i][j] = dp[i-1][j];
        		if((j - a) >= 0)
        			dp[i][j] = Math.max(dp[i-1][j], dp[i-1][j-a] + b);
        	}
        }
        
        System.out.println(dp[m][n]);
	}
}
