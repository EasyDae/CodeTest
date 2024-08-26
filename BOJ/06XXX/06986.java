//https://www.acmicpc.net/problem/6986

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		
		double[] db = new double[n + 1];
		for(int i=1; i<=n; ++i) {
			db[i] = Double.parseDouble(br.readLine());
		}
		
		Arrays.sort(db);
		
		for(int i=1; i<=n; ++i)
			db[i] += db[i-1];
		
		double avg1 = (db[n-k] - db[k])/(n - 2 * k);
		
		double avg2 = ((db[k + 1] - db[k]) * k + (db[n - k] - db[n - k - 1]) * k + (db[n - k] - db[k])) / n;
		System.out.println(String.format("%.2f", avg1 + 1e-8));
		System.out.println(String.format("%.2f", avg2 + 1e-8));
	}
}
