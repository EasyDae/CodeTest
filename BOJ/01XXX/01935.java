//https://www.acmicpc.net/problem/1935

import java.io.*;
import java.util.*;

public class Main {	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		
		Stack<Double> st = new Stack<>();
		String str = br.readLine();
		int[] arr = new int[26];
		for(int i=0; i<n; ++i) {
			int num = Integer.parseInt(br.readLine());
			arr[i] = num;
		}
		
		for(int i=0; i<str.length(); ++i) {
			char c = str.charAt(i);
			
			if(c >= 'A' && c <= 'Z')
				st.push((double)arr[c-'A']);
			else {
				double tmp1 = st.pop();
				double tmp2 = st.pop();
				switch(c) {
					case '+':
						st.push(tmp2 + tmp1);
						break;
					case '-':
						st.push(tmp2 - tmp1);
						break;
					case '*':
						st.push(tmp2 * tmp1);
						break;
					case '/':
						st.push(tmp2 / tmp1);
						break;
				}
			}
		}
		
		System.out.printf("%.2f", st.peek());
	}
}
