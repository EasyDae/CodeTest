//https://www.acmicpc.net/problem/2930

import java.io.*;
import java.math.*;

public class Main {
	
	public static int Score(char a, char b) {
		if(a==b)
			return 1;
		
		switch(a) {
		case 'R':
			return b == 'S' ? 2 : 0;
		case 'S':
			return b == 'P' ? 2 : 0;
		case 'P':
			return b == 'R' ? 2 : 0;
		default:
			return 0;
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int round = Integer.parseInt(br.readLine()); 
		String pl = br.readLine();
		int n = Integer.parseInt(br.readLine());
		String[] fr = new String[n];
		
		for(int i=0; i<n; ++i)
			fr[i] = br.readLine();
		
		int score = 0, best = 0;
		for(int i=0; i<round; ++i) {
			int r=0,s=0,p=0;
			for(int j=0; j<n; ++j) {
				char tmp = fr[j].charAt(i);
				score += Score(pl.charAt(i), tmp);
				
				r += Score('R', tmp);
				s += Score('S', tmp);
				p += Score('P', tmp);
			}
			
			best += Math.max(r, Math.max(s, p));
		}
		
		System.out.println(score);
		System.out.print(best);
	}
}
