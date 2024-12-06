//https://www.acmicpc.net/problem/5187

import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int k = Integer.parseInt(br.readLine());
        for(int t=1; t<=k; ++t) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int m = Integer.parseInt(st.nextToken()), n = Integer.parseInt(st.nextToken());
            int[] material = new int[m + 1];
            for (int i = 1; i <= m; ++i)
                material[i] = Integer.parseInt(br.readLine());

            int sum = 0;
            for (int i=0; i<n; ++i){
                st = new StringTokenizer(br.readLine());
                int h = Integer.parseInt(st.nextToken()), w = Integer.parseInt(st.nextToken());
                int d = Integer.parseInt(st.nextToken()), I = Integer.parseInt(st.nextToken());
                sum += h*w*d*material[I];
            }

            bw.write(String.format("Data Set %d:\n%d\n", t, sum));
        }
        bw.flush();
    }
}
