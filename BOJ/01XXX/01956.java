//https://www.acmicpc.net/problem/1956

import java.io.*;
import java.util.*;

public class Main {
    public static int[][] arr;
    public static int INF = 987654321;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int v = Integer.parseInt(st.nextToken());
        int e = Integer.parseInt(st.nextToken());

        arr = new int[v+1][v+1];
        for(int i=1; i<=v; ++i)
            for(int j=1; j<=v; ++j)
                if(i != j)
                    arr[i][j] = INF;

        for(int i=0; i<e; ++i){
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());

            arr[from][to] = cost;
        }

        for(int k=1; k<=v; ++k)
            for(int i=1; i<=v; ++i)
                for(int j=1; j<=v; ++j) {
                    if (arr[i][j] > arr[k][j] + arr[i][k])
                        arr[i][j] = arr[k][j] + arr[i][k];
                }

        int ans = INF;
        for(int i=1; i<=v; ++i)
            for(int j=1; j<=v; ++j)
                if(arr[i][j] != INF && arr[j][i] != INF && i != j)
                    ans = Math.min(ans, arr[i][j] + arr[j][i]);

        if(ans == INF) ans = -1;
        System.out.println(ans);
    }
}
