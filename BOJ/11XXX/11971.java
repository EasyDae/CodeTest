//https://www.acmicpc.net/problem/11971

import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String[] input = br.readLine().split(" ");
		int n = Integer.parseInt(input[0]), m = Integer.parseInt(input[1]);
		
		int[] arr1 = new int[100], arr2 = new int[100];
		int prev = 0;
		
		for(int i=0; i<n; ++i) {
			String[] input1 = br.readLine().split(" ");
			int length = Integer.parseInt(input1[0]), limit = Integer.parseInt(input1[1]);
			
			for(int j=prev; j<prev + length; ++j)
				arr1[j] = limit;
			
			prev += length;
		}
		
		prev = 0;
		
		for(int i=0; i<m; ++i) {
			String[] input1 = br.readLine().split(" ");
			int length = Integer.parseInt(input1[0]), limit = Integer.parseInt(input1[1]);
			
			for(int j=prev; j<prev + length; ++j)
				arr2[j] = limit;
			
			prev += length;
		}
		
		int max = 0;
		for(int i=0; i<100; ++i) {
			int tmp = arr2[i] - arr1[i];
			max = Math.max(max, tmp);
		}
		
		System.out.println(max);
	}
}
