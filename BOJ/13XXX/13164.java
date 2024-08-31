//https://www.acmicpc.net/problem/13164

import java.io.*;
import java.util.*;

public class Main {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		String[] input = br.readLine().split(" ");
		List<Integer> arr = new ArrayList<>();
		for(int i=1; i<n; ++i)
			arr.add(Integer.parseInt(input[i]) - Integer.parseInt(input[i-1]));
		
		Collections.sort(arr);
		
		int ans = 0;
		for(int i=0; i<n - k; ++i)
			ans += arr.get(i);
		
		System.out.println(ans);
	}
}
