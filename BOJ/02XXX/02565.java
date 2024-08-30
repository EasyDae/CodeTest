//https://www.acmicpc.net/problem/2565

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int[][] wire = new int[n][2];
		for(int i=0; i<n; ++i) {
			st = new StringTokenizer(br.readLine());
			
			wire[i][0] = Integer.parseInt(st.nextToken());
			wire[i][1] = Integer.parseInt(st.nextToken());
		}
		
		Arrays.sort(wire, Comparator.comparingInt(a -> a[0]));
		
		int max = 0;
		int[] dp = new int[n];
		for(int i=0; i<n; ++i) {
			dp[i] = 1;
			for(int j=0; j<i; ++j)
				if(wire[i][1] > wire[j][1])
					dp[i] = Math.max(dp[i], dp[j]+1);
			max = Math.max(max, dp[i]);
		}
		
		System.out.println(n - max);
	}
}
