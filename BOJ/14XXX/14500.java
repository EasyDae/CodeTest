//https://www.acmicpc.net/problem/14500

import java.io.*;
import java.util.*;

public class Main {
    static int[][] map;
    static boolean[][] visited;
    static int[] dx = {1,-1,0,0};
    static int[] dy = {0,0,1,-1};
    static int n, m, max, maxVal;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new int[n][m];
        visited = new boolean[n][m];

        for(int i=0; i<n; ++i){
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<m; ++j){
                map[i][j] = Integer.parseInt(st.nextToken());
                maxVal = Math.max(maxVal, map[i][j]);
            }
        }
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                visited[i][j] = true;
                DFS(i, j, 0, map[i][j]);
                visited[i][j] = false;
            }
        }
        
        System.out.println(max);
    }

    static void DFS(int x, int y, int depth, int sum){
        if(depth == 3){
            max = Math.max(max, sum);
            return;
        }
        if(max > sum + maxVal * (4 - depth))
            return;

        for(int i=0; i<4; ++i){
            int ax = x + dx[i];
            int ay = y + dy[i];
            if(ax < 0 || ax >= n || ay < 0 || ay >= m || visited[ax][ay])
                continue;

            if(depth == 1){
                visited[ax][ay] = true;
                DFS(x, y, depth + 1, sum + map[ax][ay]);
                visited[ax][ay] = false;
            }

            visited[ax][ay] = true;
            DFS(ax, ay, depth + 1, sum + map[ax][ay]);
            visited[ax][ay] = false;
        }
    }
}
