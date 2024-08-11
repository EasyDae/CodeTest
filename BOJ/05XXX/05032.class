//https://www.acmicpc.net/problem/5032

import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();
		String[] str = input.split(" ");
		int e = Integer.parseInt(str[0]), f = Integer.parseInt(str[1]), c = Integer.parseInt(str[2]), cnt = 0, bottle = e + f;
		while(true) {
			if(bottle < c)
				break;
			
			cnt += bottle/c;
			bottle = bottle/c + bottle%c;
		}
		
		System.out.println(cnt);
	}
}
