//https://www.acmicpc.net/problem/22233

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String[] input = br.readLine().split(" ");
		int n = Integer.parseInt(input[0]);
		int m = Integer.parseInt(input[1]);
		
		Map<String, Integer> map = new HashMap<>();
		for(int i=0; i<n; ++i) {
			map.put(br.readLine(), 1);
		}
		
		for(int i=0; i<m; ++i) {
			input = br.readLine().split(",");
			
			for(var x : input) {
				if(map.containsKey(x)) {
					n--;
					map.remove(x);
				}
			}
			
			System.out.println(n);
		}
	}
}
