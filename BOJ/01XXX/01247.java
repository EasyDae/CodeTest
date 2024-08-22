//https://www.acmicpc.net/problem/1247

import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		for(int i=0; i<3; ++i) {
			int n = Integer.parseInt(br.readLine());
			BigInteger sum = BigInteger.ZERO;
			for(int j=0; j<n; ++j) {
				BigInteger tmp = new BigInteger(br.readLine());
				sum = sum.add(tmp);
			}
			
			int comp = sum.compareTo(new BigInteger("0"));
			if(comp > 0)
				System.out.println('+');
			else if(comp == 0)
				System.out.println(0);
			else
				System.out.println('-');
		}
	}
}
