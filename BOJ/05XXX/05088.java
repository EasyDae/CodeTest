//https://www.acmicpc.net/problem/5088

import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        while(true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            if(x==0 && y==0){
                System.out.print(sb);
                return;
            }

            int[][] arr = new int[x + 1][y + 1];
            int m = Integer.parseInt(br.readLine());
            for (int i = 0; i < m; ++i) {
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                arr[a][b]++;
            }

            int n = Integer.parseInt(br.readLine());
            int ans = 0;
            for (int i = 0; i < n; ++i) {
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                ans += arr[a][b];
            }
            sb.append(ans).append('\n');
        }
    }
}
