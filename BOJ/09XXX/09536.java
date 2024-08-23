//https://www.acmicpc.net/problem/9536

import java.io.*;
import java.util.*;

public class Main {	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(br.readLine());
		Map<String, String> animal = new HashMap<>();
		
		for(int i=0; i<t; ++i) {
			String[] howling = br.readLine().split(" ");
			
			while(true) {
				String[] input = br.readLine().split(" ");
				if(!input[1].equals("goes"))
					break;
				
				animal.put(input[0], input[2]);
			}
			
			for(int j=0; j<howling.length; ++j) {
				if(!animal.containsValue(howling[j]))
					System.out.print(howling[j] + " ");
			}
			
			System.out.println();
		}
	}
}
