//https://www.acmicpc.net/problem/2417

import java.io.*;
import java.math.*;

public class Main {	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		BigInteger n = new BigInteger(br.readLine());
		BigInteger start = BigInteger.ZERO;
		BigInteger mid;
		BigInteger end = n;
		while(start.compareTo(end) <= 0) {
			mid = start.add(end).divide(BigInteger.TWO);
			int comp = mid.multiply(mid).compareTo(n);
			
			if(comp == 0) {
				System.out.println(mid);
				return;
			}
			else if(comp > 0)
				end = mid.subtract(BigInteger.ONE);
			else
				start = mid.add(BigInteger.ONE);
		}
		
		System.out.println(start);
	}
}
