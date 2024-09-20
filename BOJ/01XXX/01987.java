//https://www.acmicpc.net/problem/1987

import java.io.*;
import java.util.*;

public class Main {
    public static int[] dx = {1,-1,0,0};
    public static int[] dy = {0,0,1,-1};
    public static int[][] arr;
    public static boolean[] visited = new boolean[26];
    public static int r, c, ans = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        arr = new int[r][c];

        for(int i=0; i<r; ++i){
            String input = br.readLine();
            for(int j=0; j<c; ++j)
                arr[i][j] = input.charAt(j)-'A';
        }

        DFS(0, 0, 1);
        System.out.println(ans);
    }

    public static void DFS(int x, int y, int cnt){
        ans = Math.max(ans, cnt);
        if(visited[arr[x][y]]){
            return;
        }
        else{
            visited[arr[x][y]] = true;
            for(int i=0; i<4; ++i){
                int ax = x + dx[i];
                int ay = y + dy[i];

                if(ax < 0 || ax >= r || ay < 0 || ay >= c || visited[arr[ax][ay]])
                    continue;

                DFS(ax, ay, cnt + 1);
            }
            visited[arr[x][y]] = false;
        }
    }
}
