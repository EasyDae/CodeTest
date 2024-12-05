//https://www.acmicpc.net/problem/13222

import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), w = Integer.parseInt(st.nextToken()), h = Integer.parseInt(st.nextToken());
        int len = (int) Math.sqrt(Math.pow(w, 2) + Math.pow(h, 2));

        for(int i=0; i<n; ++i){
            int input = Integer.parseInt(br.readLine());
            bw.write(input > len ? "NO\n" : "YES\n");
        }
        bw.flush();
    }
}
