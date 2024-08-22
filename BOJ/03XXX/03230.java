//https://www.acmicpc.net/problem/3230

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		List<Integer> list1 = new ArrayList<>(), list2 = new ArrayList<>();
		String[] input = br.readLine().split(" ");
		int n = Integer.parseInt(input[0]), m = Integer.parseInt(input[1]);
		
		for(int i=1; i<=n; ++i) {
			int rank = Integer.parseInt(br.readLine());
			list1.add(rank - 1, i);
		}
		
		for(int i=m-1; i>=0;--i) {
			int rank = Integer.parseInt(br.readLine());
			list2.add(rank - 1, list1.get(i));
		}
		
		System.out.println(list2.get(0));
		System.out.println(list2.get(1));
		System.out.println(list2.get(2));
	}
}
