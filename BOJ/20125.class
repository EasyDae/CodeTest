//https://www.acmicpc.net/problem/20125

import java.io.*;

public class Main {	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		
		String[] arr = new String[n];
		for(int i=0; i<n; ++i)
			arr[i] = br.readLine();
		
		int x = 0, y = 0;
		for(int i=1; i<n - 1; ++i) {
			for(int j=1; j<n - 1; ++j) {
				if(arr[i].charAt(j) == '*' && arr[i-1].charAt(j) == '*' && arr[i+1].charAt(j) == '*' && arr[i].charAt(j-1) == '*' && arr[i].charAt(j + 1) == '*') {
					x = i;
					y = j;
					break;
				}
			}
			if(x != 0 || y != 0)
				break;
		}
		
		int leftarm = 0;
		for(int i=y-1; i>=0; --i) {
			if(arr[x].charAt(i) != '*')
				break;
			leftarm++;
		}
		
		int rightarm = 0;
		for(int i=y+1; i<n; ++i) {
			if(arr[x].charAt(i) != '*')
				break;
			rightarm++;
		}
		
		int waist = 0, end = 0;
		for(int i=x+1; i<n; ++i) {
			if(arr[i].charAt(y) != '*') {
				end = i;
				break;
			}
			waist++;
		}
		
		int leftleg = 0;
		for(int i=end; i<n; ++i) {
			if(arr[i].charAt(y - 1) != '*')
				break;
			leftleg++;
		}
		
		
		int rightleg = 0;
		for(int i=end; i<n; ++i) {
			if(arr[i].charAt(y + 1) != '*')
				break;
			rightleg++;
		}
		
		System.out.println((x+1) + " " + (y+1));
		System.out.println(leftarm + " " + rightarm + " " + waist + " " + leftleg + " " + rightleg);
	}
}
