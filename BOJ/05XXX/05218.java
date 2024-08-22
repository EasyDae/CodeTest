//https://www.acmicpc.net/problem/5218

import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		
		for(int i=0; i<n; ++i) {
			String[] str = br.readLine().split(" ");
			
			int[] arr = new int[str[0].length()];
			for(int j=0; j<str[0].length(); ++j) {
				if(str[1].charAt(j) >= str[0].charAt(j))
					arr[j] = str[1].charAt(j) - str[0].charAt(j);
				else
					arr[j] = str[1].charAt(j) - str[0].charAt(j) + 26;
			}
			
			System.out.print("Distances: ");
			for(int j=0; j<str[0].length(); ++j)
				System.out.print(arr[j] + " ");
			
			System.out.println();
		}
	}
}
