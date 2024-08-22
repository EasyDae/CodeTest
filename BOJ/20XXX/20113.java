//https://www.acmicpc.net/problem/20113

import java.io.*;
import java.math.*;
import java.util.Arrays;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		int[] arr = new int[n];
		String[] input = br.readLine().split(" ");
		
		for(int i=0; i<n; ++i) {
			int idx = Integer.parseInt(input[i]);
			if(idx == 0)
				continue;
			
			arr[idx-1]++;
		}
		
		int Max = Arrays.stream(arr).max().orElseThrow(), cnt = 0, idx = 0;
		for(int i=0; i<n; ++i)
			if(arr[i] == Max) {
				cnt++;
				idx = i;
			}
		
		if(cnt > 1)
			System.out.println("skipped");
		else
			System.out.println((idx + 1));
	}
}
