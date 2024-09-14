//https://www.acmicpc.net/problem/14938

import java.io.*;
import java.util.*;

public class Main {
    public static int[] item;
    public static int[][] map;
    public static int INF = 987654321;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());

        item = new int[n+1];
        st = new StringTokenizer(br.readLine());
        for(int i=1; i<=n; ++i)
            item[i] = Integer.parseInt(st.nextToken());

        map = new int[n+1][n+1];
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=n; ++j)
                if(i!=j)
                    map[i][j] = INF;

        for(int i=0; i<r; ++i){
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            map[a][b] = map[b][a] = c;
        }

        for(int k=1; k<=n; ++k)
            for(int i=1; i<=n; ++i)
                for(int j=1; j<=n; ++j)
                    map[i][j] = Math.min(map[i][j], map[i][k] + map[k][j]);

        int ans = 0;
        for(int i=1; i<=n; ++i){
            int sum = item[i];

            for(int j=1; j<=n; ++j)
                if(i!=j && map[i][j] <= m)
                    sum += item[j];

            ans = Math.max(ans, sum);
        }

        System.out.println(ans);
    }
}
