//https://www.acmicpc.net/problem/2573

import java.io.*;
import java.util.*;

class Ice{
    int x, y;

    Ice(int x, int y){
        this.x = x;
        this.y = y;
    }
}

public class Main {
    public static int n, m;
    public static int[][] arr;
    public static int[] dx = {1, -1, 0, 0};
    public static int[] dy = {0, 0, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new int[n][m];

        for(int i=0; i<n; ++i) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; ++j)
                arr[i][j] = Integer.parseInt(st.nextToken());
        }

        int time = 0, cnt = 0;
        while((cnt = check()) < 2){
            if(cnt == 0){
                System.out.println(0);
                return;
            }

            melt();
            time++;
        }
        System.out.println(time);
    }

    public static int check(){
        boolean[][] visited = new boolean[n][m];

        int cnt = 0;
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
                if(!visited[i][j] && arr[i][j] != 0){
                    DFS(i, j, visited);
                    cnt++;
                }

        return cnt;
    }

    public static void DFS(int x, int y, boolean[][] visited){
        visited[x][y] = true;

        for(int i=0; i<4; ++i){
            int ax = x + dx[i];
            int ay = y + dy[i];

            if(ax < 0 || ax >= n || ay < 0 || ay >= m || visited[ax][ay] || arr[ax][ay] == 0)
                continue;

            DFS(ax, ay, visited);
        }
    }

    public static void melt(){
        Queue<Ice> q = new LinkedList<>();
        boolean[][] visited = new boolean[n][m];
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
                if(arr[i][j] != 0) {
                    q.offer(new Ice(i, j));
                    visited[i][j] = true;
                }

        while(!q.isEmpty()){
            Ice ice = q.poll();
            int seacnt = 0;

            for(int i=0; i<4; ++i){
                int ax = ice.x + dx[i];
                int ay = ice.y + dy[i];

                if(ax < 0 || ax >= n || ay < 0 || ay >= m || visited[ax][ay] || arr[ax][ay] != 0)
                    continue;

                seacnt++;
            }

            arr[ice.x][ice.y] = Math.max(arr[ice.x][ice.y] - seacnt, 0);
        }
    }
}
