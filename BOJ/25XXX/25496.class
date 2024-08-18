//https://www.acmicpc.net/problem/25496

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String[] input = br.readLine().split(" ");
		int p = Integer.parseInt(input[0]), n = Integer.parseInt(input[1]);
		int cnt = 0;
		
		List<Integer> list = new ArrayList<>(n);
		input = br.readLine().split(" ");
		
		for(int i=0; i<n; ++i) {
			list.add(Integer.parseInt(input[i]));
		}
		
		list.sort(null);
		
		for(int i=0; i<n; ++i) {
			if(p < 200) {
				p += list.get(i);
				cnt++;
			}
		}
		
		System.out.println(cnt);
	}
}
