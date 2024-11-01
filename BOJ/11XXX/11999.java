//https://www.acmicpc.net/problem/11999

import java.io.*;
import java.util.*;

public class Main {
    public static int x, y, m;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        x = Integer.parseInt(st.nextToken());
        y = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        int ans = 0;
        for(int i=0; i<=1000; ++i)
            for(int j=0; j<=1000; ++j){
                int sum = x*i + y*j;
                if(sum <= m)
                    ans = Math.max(ans, sum);
            }

        System.out.print(ans);
    }
}
