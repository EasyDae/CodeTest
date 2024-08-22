//https://www.acmicpc.net/problem/11023

import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();
		String[] str = input.split(" ");
		
		int ans = 0;
		for(String s : str) {
			ans += Integer.parseInt(s);
		}
		
		System.out.println(ans);
	}
}
