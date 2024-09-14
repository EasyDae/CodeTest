//https://www.acmicpc.net/problem/1613

import java.io.*;
import java.util.*;

public class Main {
    public static int[][] arr;
    public static int INF = 987654321;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        arr = new int[n+1][n+1];
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=n; ++j)
                if(i!=j) arr[i][j] = INF;

        for(int i = 0; i< k; ++i){
            st = new StringTokenizer(br.readLine());

            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            arr[from][to] = 1;
        }

        for(int l=1; l<=n; ++l)
            for(int i=1; i<=n; ++i)
                for(int j=1; j<=n; ++j)
                    arr[i][j] = Math.min(arr[i][j], arr[i][l] + arr[l][j]);

        int s = Integer.parseInt(br.readLine());

        StringBuilder sb = new StringBuilder();
        for(int i=0; i<s; ++i){
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            if(arr[a][b] == INF && arr[b][a] == INF)
                sb.append(0 + "\n");
            else if(arr[a][b] != INF && arr[b][a] == INF)
                sb.append(-1 + "\n");
            else if(arr[a][b] == INF && arr[b][a] != INF)
                sb.append(1 + "\n");
        }

        System.out.println(sb);
    }
}
