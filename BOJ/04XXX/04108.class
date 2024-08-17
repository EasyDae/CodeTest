//https://www.acmicpc.net/problem/4108

import java.io.*;

public class Main {
	public static int Count(int x, int y, String[] str, int r, int c) {
		int[] dx = {1,1,1,0,0,-1,-1,-1};
		int[] dy = {1,0,-1,1,-1,1,0,-1};
		int cnt = 0;
		
		for(int i=0; i<8; ++i) {
			int ax = x + dx[i];
			int ay = y + dy[i];
			
			if(ax < 0 || ax >= r || ay < 0 || ay >= c)
				continue;
			
			if(str[ax].charAt(ay) == '*')
				cnt++;
		}
		
		return cnt;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		while(true) {
			String[] input = br.readLine().split(" ");
			int r = Integer.parseInt(input[0]), c = Integer.parseInt(input[1]);
			if(r==0 && c == 0)
				return;
			
			String[] arr = new String[r];
			for(int i=0; i<r; ++i)
				arr[i] = br.readLine();
			
			for(int i=0; i<r; ++i)
				for(int j=0; j<c; ++j) {
					if(arr[i].charAt(j) != '*') {
						int cnt = Count(i,j,arr,r,c);
						StringBuilder sb = new StringBuilder(arr[i]);
						sb.setCharAt(j, (char)(cnt + '0'));
						arr[i] = sb.toString();
					}
				}
			
			for(int i=0; i<r; ++i) {
				System.out.println(arr[i]);
			}
		}
	}
}
