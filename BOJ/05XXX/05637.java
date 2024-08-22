//https://www.acmicpc.net/problem/5637

import java.io.*;

public class Main {	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int max = 0;
		String str = null;
		
		while(true) {
			String s = br.readLine();
            String[] split = s.toLowerCase().split("[^a-z-]");
            for (String cur : split) {
                if (cur.equals("e-n-d")) {
                    System.out.println(str.toLowerCase());
                    return;
                }
                if (max < cur.length()) {
                    max = cur.length();
                    str = cur;
                }
            }
		}
	}
}
