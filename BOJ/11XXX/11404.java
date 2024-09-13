//https://www.acmicpc.net/problem/11404

import java.io.*;
import java.util.*;

public class Main {
    public static int[][] arr;
    public static int INF = 987654321;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());

        arr = new int[n+1][n+1];
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=n; ++j) {
                arr[i][j] = INF;

                if(i == j)
                    arr[i][j] = 0;
            }

        for(int i=0; i<m; ++i){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());

            arr[from][to] = Math.min(arr[from][to], cost);
        }

        for(int k=1; k<=n; ++k)
            for(int i=1; i<=n; ++i)
                for(int j=1; j<=n; ++j)
                    if(arr[i][j] > arr[k][j] + arr[i][k])
                        arr[i][j] = arr[k][j] + arr[i][k];

        for(int i=1; i<=n; ++i)
            for(int j=1; j<=n; ++j)
                if(arr[i][j] == INF)
                    arr[i][j] = 0;

        StringBuilder sb = new StringBuilder();
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j)
                sb.append(arr[i][j] + " ");
            sb.append("\n");
        }
        System.out.print(sb);
    }
}
