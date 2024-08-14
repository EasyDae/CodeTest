//https://www.acmicpc.net/problem/28063

import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String input = br.readLine();
		int n = Integer.parseInt(input);
		if(n == 1)
			System.out.println(0);
		else {
			String[] str = br.readLine().split(" ");
			int x = Integer.parseInt(str[0]), y = Integer.parseInt(str[1]);
			
			if((x==1 && y == 1) || (x==1 && y == n) || (x == n && y == 1) || (x == n && y == n))
				System.out.println(2);
			else if(x == 1 || y == 1 || x == n || y == n)
				System.out.println(3);
			else
				System.out.println(4);
		}
	}
}
