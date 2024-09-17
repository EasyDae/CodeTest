//https://www.acmicpc.net/problem/1261

import java.io.*;
import java.util.*;

class Node implements Comparable<Node>{
    int x;
    int y;
    int cnt;

    public Node(int x, int y, int cnt){
        this.x = x;
        this.y = y;
        this.cnt = cnt;
    }

    @Override
    public int compareTo(Node n){
        return this.cnt - n.cnt;
    }
}

public class Main {
    public static int n, m;
    public static int[][] arr;
    public static int[] dx = {1,-1,0,0};
    public static int[] dy = {0,0,1,-1};
    public static boolean[][] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());

        arr = new int[n][m];
        visited = new boolean[n][m];
        for(int i=0; i<n; ++i){
            String input = br.readLine();
            for(int j=0; j<m; ++j)
                arr[i][j] = Character.getNumericValue(input.charAt(j));
        }

        System.out.println(BFS(0,0));
    }

    public static int BFS(int x, int y){
        Queue<Node> pq = new PriorityQueue<>();
        pq.add(new Node(x, y, 0));
        visited[x][y] = true;

        while(!pq.isEmpty()){
            Node nd = pq.poll();
            if(nd.x == n - 1 && nd.y == m - 1)
                return nd.cnt;

            for(int i=0; i<4; ++i){
                int ax = nd.x + dx[i];
                int ay = nd.y + dy[i];

                if(ax < 0 || ax >= n || ay < 0 || ay >= m || visited[ax][ay])
                    continue;

                visited[ax][ay] = true;
                if(arr[ax][ay] == 0)
                    pq.add(new Node(ax, ay, nd.cnt));
                else
                    pq.add(new Node(ax, ay, nd.cnt + 1));
            }
        }
        return 0;
    }
}
