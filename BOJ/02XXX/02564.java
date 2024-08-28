//https://www.acmicpc.net/problem/2564

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int cnt = Integer.parseInt(br.readLine());
		
		int[] arr = new int[cnt + 1];
		for(int i=0; i<cnt+1; ++i) {
			st = new StringTokenizer(br.readLine());
			
			int dir = Integer.parseInt(st.nextToken());
			int loc = Integer.parseInt(st.nextToken());
			int dist = 0;
			
			switch(dir) {
			case 1:
				dist = loc;
				break;
			case 2:
				dist = 2 * n + m - loc;
				break;
			case 3:
				dist = 2 * n + 2 * m - loc;
				break;
			case 4:
				dist = n + loc;
				break;
			}
			arr[i] = dist;
		}
		
		int ans = 0;
		for(int i=0; i<cnt; ++i) {
			int dist1 = Math.abs(arr[cnt] - arr[i]);
			int dist2 = 2 * n + 2 * m - dist1;
			
			ans += Math.min(dist1, dist2);
		}
		
		System.out.println(ans);
	}
}
