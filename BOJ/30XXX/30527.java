//https://www.acmicpc.net/problem/30527

import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int total = 0;
        for(int i=0; i<5; ++i){
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            total += a * b;
        }
        st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int kwf = Integer.parseInt(st.nextToken());

        System.out.print(((total/5) * n) / kwf);
    }
}
