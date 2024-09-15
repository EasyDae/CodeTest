//https://www.acmicpc.net/problem/17182

import java.io.*;
import java.util.*;

public class Main {
    public static int[][] arr;
    public static boolean[] visited;
    public static int ans = 987654321;
    public static int n, k;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        arr = new int[n][n];
        visited = new boolean[n];
        for(int i=0; i<n; ++i){
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<n; ++j)
                arr[i][j] = Integer.parseInt(st.nextToken());
        }

        for(int l=0; l<n; ++l)
            for(int i=0; i<n; ++i)
                for(int j=0; j<n; ++j)
                    arr[i][j] = Math.min(arr[i][j], arr[i][l] + arr[l][j]);
        visited[k] = true;

        DFS(0, k, 0);
        System.out.println(ans);
    }

    public static void DFS(int depth, int start, int sum){
        if(depth == n-1) {
            ans = Math.min(ans, sum);
            return;
        }

        for(int i=0; i<n; ++i){
            if(visited[i]) continue;
            visited[i] = true;
            DFS(depth + 1, i, sum + arr[start][i]);
            visited[i] = false;
        }
    }
}
