//https://www.acmicpc.net/problem/2547

import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(br.readLine());
		for(int i=0; i<t; ++i) {
			br.readLine();
			int n = Integer.parseInt(br.readLine());
			BigInteger sum = BigInteger.ZERO;
			for(int j=0; j<n; ++j)
				sum = sum.add(BigInteger.valueOf(Long.parseLong(br.readLine())));
			
			System.out.println((String.valueOf(sum.remainder(BigInteger.valueOf(n))).equals("0"))? "YES":"NO");
		}
	}
}
