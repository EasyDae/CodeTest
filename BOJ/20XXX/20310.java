//https://www.acmicpc.net/problem/20310

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String s = br.readLine();
		
		int zero = 0, one = 0;
		for(int i=0; i<s.length(); ++i) {
			if(s.charAt(i) == '0')
				zero++;
			else
				one++;
		}
		
		StringBuilder sb = new StringBuilder(s);
		
		for(int i=0; i<one/2; ++i) {
			for(int j=0; j<sb.length(); ++j)
				if(sb.charAt(j) == '1') {
					sb.deleteCharAt(j);
					break;
				}
		}
			
		for(int i=0; i<zero/2; ++i) {
			for(int j=sb.length() - 1; j >= 0; --j)
				if(sb.charAt(j) == '0') {
					sb.deleteCharAt(j);
					break;
				}
		}
		
		System.out.println(sb.toString());
	}
}
