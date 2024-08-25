//https://www.acmicpc.net/problem/2659

import java.io.*;

public class Main {
	public static int getMinNum(int a, int b, int c, int d) {
		int min = Integer.MAX_VALUE;
		
		min = Math.min(min, a * 1000 + b * 100 + c * 10 + d);
		min = Math.min(min, b * 1000 + c * 100 + d * 10 + a);
		min = Math.min(min, c * 1000 + d * 100 + a * 10 + b);
		min = Math.min(min, d * 1000 + a * 100 + b * 10 + c);
		
		return min;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String[] input = br.readLine().split(" ");
		int a = Integer.parseInt(input[0]);
		int b = Integer.parseInt(input[1]);
		int c = Integer.parseInt(input[2]);
		int d = Integer.parseInt(input[3]);
		int target = getMinNum(a,b,c,d);
		
		boolean[] visited = new boolean[10000];
		for(int i=1; i<10; ++i) {
			for(int j=1; j<10; ++j) {
				for(int k=1; k<10; ++k) {
					for(int l=1; l<10; ++l) {
						int tmp = getMinNum(i,j,k,l);
						
						visited[tmp] = true;
					}
				}
			}
		}
		
		int ans = 0;
		for(int i=1111; i<= target; ++i)
			if(visited[i])
				ans++;
		
		System.out.println(ans);
	}
}
