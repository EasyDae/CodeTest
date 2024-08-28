//https://www.acmicpc.net/problem/1918

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String input = br.readLine();
		String ans = "";
		Stack<Character> st = new Stack<>();
		
		for(int i=0; i<input.length(); ++i) {
			char ch = input.charAt(i);
			if(Character.isLetter(ch))
				ans += ch;
			else if(ch == '(')
                st.push(ch);
            else if(ch == ')') {
                while(!st.isEmpty() && st.peek() != '(')
                    ans += st.pop();
                st.pop();
            } 
            else {
                while(!st.isEmpty() && precedence(st.peek()) >= precedence(ch))
                    ans += st.pop();
                st.push(ch);
            }
		}
		
		while(!st.isEmpty())
			ans += st.pop();
		
		System.out.println(ans);
	}
	
	public static int precedence(char ch) {
		switch(ch) {
		case '+': case '-':
			return 1;
		case '*' : case '/':
			return 2;
		case '(':
			return 0;
		}
		return -1;
	}
}
