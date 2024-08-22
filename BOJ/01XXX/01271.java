//https://www.acmicpc.net/problem/1271

import java.util.Scanner;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger n = sc.nextBigInteger();
		BigInteger m = sc.nextBigInteger();
		sc.close();
		
		System.out.println(n.divide(m));
		System.out.println(n.remainder(m));
	}
}
