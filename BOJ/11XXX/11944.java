//https://www.acmicpc.net/problem/11944

import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());

        String n = st.nextToken();
		    int N = Integer.valueOf(n);
		    int m = Integer.valueOf(st.nextToken());
		    int len = n.length();
		
		    for(int i = 0; i < N * len && i <= m; i += len)
			    sb.append(n);

		    if(sb.length() > m)
			    System.out.print(sb.toString().substring(0, m));
		    else
			    System.out.print(sb.toString());
    }
}
