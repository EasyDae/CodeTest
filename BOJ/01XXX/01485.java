//https://www.acmicpc.net/problem/1485

import java.io.*;
import java.util.*;

public class Main {
	public static double distance(int[] a, int[] b) {
		return Math.sqrt(Math.pow(b[0] - a[0], 2) + Math.pow(b[1] - a[1], 2));
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(br.readLine());
		for(int i=0; i<t; ++i) {
			int[][] arr = new int[4][2];
			
			for(int j=0; j<4; ++j) {
				String[] input = br.readLine().split(" ");
				int x = Integer.parseInt(input[0]);
				int y = Integer.parseInt(input[1]);
				arr[j][0] = x; arr[j][1] = y;
			}
			
			double[] db = new double[6];
			
			db[0] = distance(arr[0], arr[1]);
			db[1] = distance(arr[0], arr[2]);
			db[2] = distance(arr[0], arr[3]);
			db[3] = distance(arr[1], arr[2]);
			db[4] = distance(arr[1], arr[3]);
			db[5] = distance(arr[2], arr[3]);
			
			Arrays.sort(db);
			
			if(db[0] == db[1] && db[1] == db[2] && db[2] == db[3] && db[4] == db[5] && db[1] != 0)
				System.out.println(1);
			else
				System.out.println(0);
		}
	}
}
