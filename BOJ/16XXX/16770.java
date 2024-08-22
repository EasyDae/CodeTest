//https://www.acmicpc.net/problem/16770

import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		int[] arr = new int[1001];
		
		for(int i=0; i<n; ++i) {
			String[] str = br.readLine().split(" ");
			
			int start = Integer.parseInt(str[0]), end = Integer.parseInt(str[1]), bucket = Integer.parseInt(str[2]);
			arr[start] += bucket;
			arr[end] -= bucket;
		}
		
		int cnt = 0, ans = 0;
		for(int i=0; i<=1000; ++i) {
			cnt += arr[i];
			ans = Math.max(cnt, ans);
		}
		
		System.out.println(ans);
	}
}
