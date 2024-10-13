//https://www.acmicpc.net/problem/16946

import java.io.*;
import java.util.*;

class Coord{
    int x, y;

    public Coord(int x, int y){
        this.x = x;
        this.y = y;
    }
}

public class Main {
    public static int n, m, idx = 1;
    public static char[][] arr;
    public static int[][] group;
    public static int[] dx = {1,-1,0,0};
    public static int[] dy = {0,0,1,-1};
    public static HashMap<Integer, Integer> map = new HashMap<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new char[n][m];
        group = new int[n][m];
        for(int i=0; i<n; ++i)
            arr[i] = br.readLine().toCharArray();

        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
                if(arr[i][j] == '0' && group[i][j] == 0)
                    map.put(idx, BFS(i, j, idx++));

        StringBuilder sb = new StringBuilder();
        for(int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                sb.append(Count(i, j));
            }
            sb.append('\n');
        }

        System.out.println(sb);
    }

    public static int Count(int x, int y){
        if(arr[x][y] == '0')
            return 0;

        int sum = 1;
        HashSet<Integer> st = new HashSet<>();

        for(int i=0; i<4; ++i){
            int ax = x + dx[i];
            int ay = y + dy[i];

            if(ax < 0 || ax >= n || ay < 0 || ay >= m || group[ax][ay] == 0 || arr[ax][ay] != '0')
                continue;

            st.add(group[ax][ay]);
        }

        for(int tmp : st){
            sum += map.get(tmp);
        }

        return sum%10;
    }

    public static int BFS(int x, int y, int grp){
        Queue<Coord> q = new LinkedList<>();
        q.offer(new Coord(x, y));
        group[x][y] = grp;
        int cnt = 1;

        while(!q.isEmpty()){
            Coord cur = q.poll();

            for(int i=0; i<4; ++i){
                int ax = cur.x + dx[i];
                int ay = cur.y + dy[i];

                if(ax < 0 || ax >= n || ay < 0 || ay >= m || arr[ax][ay] != '0' || group[ax][ay] != 0)
                    continue;

                q.offer(new Coord(ax, ay));
                group[ax][ay] = grp;
                cnt++;
            }
        }

        return cnt;
    }
}
