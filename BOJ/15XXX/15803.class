//https://www.acmicpc.net/problem/15803

import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int x1,y1,x2,y2,x3,y3;
		String[] input1 = br.readLine().split(" ");
		String[] input2 = br.readLine().split(" ");
		String[] input3 = br.readLine().split(" ");
		
		x1 = Integer.parseInt(input1[0]); y1 = Integer.parseInt(input1[1]);
		x2 = Integer.parseInt(input2[0]); y2 = Integer.parseInt(input2[1]);
		x3 = Integer.parseInt(input3[0]); y3 = Integer.parseInt(input3[1]);
		
		if(((x1*y2 + x2*y3 + x3*y1) - (x2*y1 + x3*y2 + x1*y3))/2.0 == 0)
			System.out.println("WHERE IS MY CHICKEN?");
		else
			System.out.println("WINNER WINNER CHICKEN DINNER!");
	}
}
