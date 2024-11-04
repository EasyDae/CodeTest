//https://www.acmicpc.net/problem/11815

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        for(int i=0; i<n; ++i){
            long num = Long.parseLong(st.nextToken());
            long sqrt = (long)Math.sqrt(num);
            sb.append(sqrt*sqrt==num? 1 : 0).append(' ');
        }
        System.out.print(sb);
    }
}
