//https://www.acmicpc.net/problem/17176

import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		int[] arr = new int[53];
		
		String[] input = br.readLine().split(" ");
		for(int i=0; i<n; ++i)
			arr[Integer.parseInt(input[i])]++;
		
		String str = br.readLine();
		for(int i=0; i<str.length(); ++i) {
			if(str.charAt(i) != ' ') {
				if(Character.isUpperCase(str.charAt(i)))
					arr[str.charAt(i) - 64]--;
				else
					arr[str.charAt(i) - 70]--;
			}
			else
				arr[0]--;
		}
		
		for(int i=0; i<53; ++i) {
			if(arr[i] != 0) {
				System.out.println('n');
				return;
			}
		}
		
		System.out.println('y');
	}
}
