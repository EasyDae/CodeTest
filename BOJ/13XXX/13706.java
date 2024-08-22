//https://www.acmicpc.net/problem/13706

import java.io.*;
import java.math.*;

public class Main {	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		BigInteger n = new BigInteger(br.readLine());
		
		BigInteger start = BigInteger.ONE;
		BigInteger mid;
		BigInteger end = n;
		while(true) {
			mid = start.add(end).divide(BigInteger.TWO);
			int result = mid.multiply(mid).compareTo(n);
			if(result == 0) {
				System.out.println(mid);
				return;
			}
			else if(result > 0)
				end = mid.subtract(BigInteger.ONE);
			else
				start = mid.add(BigInteger.ONE);
		}
	}
}
