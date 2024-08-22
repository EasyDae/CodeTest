//https://www.acmicpc.net/problem/1063

import java.io.*;

public class Main {	
	static int x1, y1, x2, y2;
	
	public static void move(int y, int x) {
		if(x1 + x < 0 || x1 + x >= 8 || y1 + y < 0 || y1 + y >= 8)
			return;
		
		if(x1 + x == x2 && y1 + y == y2) {
			if(x2 + x < 0 || x2 + x >= 8 || y2 + y < 0 || y2 + y >= 8)
				return;
			
			x2 += x; y2 += y;
		}
		x1 += x; y1 += y;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String[] input = br.readLine().split(" ");
		x1 = input[0].charAt(0)-'A';
		y1 = input[0].charAt(1)-'1';
		
		x2 = input[1].charAt(0)-'A';
		y2 = input[1].charAt(1)-'1';
		
		int n = Integer.parseInt(input[2]);
		
		for(int i=0; i<n; ++i) {
			String dir = br.readLine();
			
			switch(dir) {
			case "R":
				move(0, 1);
				break;
			case "L":
				move(0, -1);
				break;
			case "B":
				move(-1, 0);
				break;
			case "T":
				move(1, 0);
				break;
			case "RT":
				move(1, 1);
				break;
			case "LT":
				move(1, -1);
				break;
			case "RB":
				move(-1, 1);
				break;
			case "LB":
				move(-1, -1);
				break;
			default:
				break;
			}
		}
		
		System.out.printf("%c%d\n", x1 + 'A', y1 + 1);
		System.out.printf("%c%d", x2 + 'A', y2 + 1);
	}
}
