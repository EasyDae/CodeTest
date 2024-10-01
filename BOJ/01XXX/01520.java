//https://steady-coding.tistory.com/142

import java.io.*;
import java.util.*;

public class Main {
    public static int m, n;
    public static int[][] arr, dp;
    public static int[] dx = {1, -1, 0, 0};
    public static int[] dy = {0, 0, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        arr = new int[m][n];
        dp = new int[m][n];

        for(int i=0; i<m; ++i){
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<n; ++j)
                arr[i][j] = Integer.parseInt(st.nextToken());
        }

        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j)
                dp[i][j] = -1;

        System.out.println(DFS(0, 0));
    }

    public static int DFS(int x, int y){
        if(x == m - 1 && y == n - 1)
            return 1;

        if(dp[x][y] != -1)
            return dp[x][y];

        dp[x][y] = 0;
        for(int i=0; i<4; ++i){
            int ax = x + dx[i];
            int ay = y + dy[i];

            if(ax < 0 || ax >= m || ay < 0 || ay >= n)
                continue;

            if(arr[x][y] > arr[ax][ay])
                dp[x][y] += DFS(ax, ay);
        }
        return dp[x][y];
    }
}
