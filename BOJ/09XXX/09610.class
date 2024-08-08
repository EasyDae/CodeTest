//https://www.acmicpc.net/problem/9610

import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		int q1 = 0, q2 = 0, q3 = 0, q4 = 0, axis = 0;
		for(int i=0; i<t; ++i) {
			String input = br.readLine();
			String[] str = input.split(" ");
			int x = Integer.parseInt(str[0]), y = Integer.parseInt(str[1]);
			if(x==0 || y == 0)
				axis++;
			else if(x > 0 && y > 0)
				q1++;
			else if(x > 0 && y < 0)
				q4++;
			else if(x < 0 && y < 0)
				q3++;
			else
				q2++;
		}
		
		System.out.println("Q1: " + q1);
		System.out.println("Q2: " + q2);
		System.out.println("Q3: " + q3);
		System.out.println("Q4: " + q4);
		System.out.println("AXIS: " + axis);
	}
}
