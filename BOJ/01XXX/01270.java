//https://www.acmicpc.net/problem/1270

import java.io.*;
import java.util.*;

public class Main {	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine());
		int a = Integer.parseInt(st.nextToken());
		while(a --> 0) {
			System.gc();
			st = new StringTokenizer(br.readLine());
			int b = Integer.parseInt(st.nextToken());
			Map<Long, Integer> m = new HashMap<>();
			int max = 0;
			long idx = 0;
			for(int i = 0; i < b; i++) {
				long k = Long.parseLong(st.nextToken());
				m.put(k, m.getOrDefault(k, 0) + 1);
				if(m.get(k) > max) {
					max = m.get(k);
					idx = k;
				}
			}
			if(max > (double)b / 2) {sb.append(idx+"\n");}
			else {sb.append("SYJKGW\n");}
		}
		bw.write(sb.toString());	
		bw.flush();
		bw.close();
		br.close();
	}
}
