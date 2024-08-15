//https://www.acmicpc.net/problem/9494

import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		while(true) {
			int n = Integer.parseInt(br.readLine());
			if(n==0)
				return;
			
			int column = 0;
            
            for(int i = 0; i < n; ++i) {
                String str = br.readLine();
                
                while(column < str.length() && str.charAt(column) != ' ')
                    column++;
            }
            
            System.out.println(column + 1);
		}
	}
}
