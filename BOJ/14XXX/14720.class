//https://www.acmicpc.net/problem/14720

import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		String[] input = br.readLine().split(" ");
		
		int prev = -1, cnt = 0;
		for(int i=0; i<n; ++i) {
			if(prev == -1) {
				if(input[i].equals("0")) {
					prev = 0;
					cnt++;
				}
			}
			else if(prev == 0) {
				if(input[i].equals("1")) {
					prev = 1;
					cnt++;
				}
			}
			else if(prev== 1) {
				if(input[i].equals("2")) {
					prev = 2;
					cnt++;
				}
			}
			else {
				if(input[i].equals("0")) {
					prev = 0;
					cnt++;
				}
			}
		}
		
		System.out.println(cnt);
	}
}
