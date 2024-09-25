//https://www.acmicpc.net/problem/3190

import java.io.*;
import java.util.*;

class Node{
    int x, y;

    public Node(int x, int y){
        this.x = x;
        this.y = y;
    }
}

class cmd{
    int time;
    char dir;

    public cmd(int time, char dir){
        this.time = time;
        this.dir = dir;
    }
}

public class Main{
    public static int[][] arr;
    public static Queue<cmd> cq;
    public static int[] dx = {-1, 0, 1, 0};
    public static int[] dy = {0, 1, 0, -1};
    public static int n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        n = Integer.parseInt(br.readLine());
        int k = Integer.parseInt(br.readLine());

        arr = new int[n+1][n+1];
        for(int i=0; i<k; ++i){
            st = new StringTokenizer(br.readLine());

            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            arr[x][y] = 1;
        }

        int l = Integer.parseInt(br.readLine());
        cq = new LinkedList<>();
        for(int i=0; i<l; ++i){
            st = new StringTokenizer(br.readLine());

            int time = Integer.parseInt(st.nextToken());
            char dir = st.nextToken().charAt(0);

            cq.offer(new cmd(time, dir));
        }

        solve();
    }

    public static void solve(){
        int x = 1, y = 1, time = 0, dir = 1;
        Queue<Node> q = new LinkedList<>();
        q.offer(new Node(x, y));
        arr[x][y] = 2;

        while(true){
            int ax = x + dx[dir];
            int ay = y + dy[dir];

            time++;

            if(ax < 1 || ax > n || ay < 1 || ay > n || arr[ax][ay] == 2)
                break;

            if(arr[ax][ay] == 0){
                Node tmp = q.poll();
                arr[tmp.x][tmp.y] = 0;
            }
            if(!cq.isEmpty()){
                if(time == cq.peek().time){
                    cmd c = cq.poll();

                    if(c.dir == 'L')
                        dir = dir - 1 < 0 ? 3 : dir - 1;
                    else if(c.dir == 'D')
                        dir = dir + 1 > 3 ? 0 : dir + 1;
                }
            }

            arr[ax][ay] = 2;
            q.offer(new Node(ax, ay));
            x = ax;
            y = ay;
        }

        System.out.println(time);
    }
}
