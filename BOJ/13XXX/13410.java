//https://www.acmicpc.net/problem/13410

import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String[] input = br.readLine().split(" ");
		int n = Integer.parseInt(input[0]), k = Integer.parseInt(input[1]), max = 0;
		
		for(int i=1; i<=k; ++i) {
			String tmp = String.valueOf(i*n);
			StringBuilder sb = new StringBuilder(tmp);
			int reverse = Integer.parseInt(sb.reverse().toString());
			max = Math.max(max, reverse);
		}
		
		System.out.println(max);
	}
}
