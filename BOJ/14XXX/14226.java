//https://www.acmicpc.net/problem/14226

import java.io.*;
import java.util.*;

class Node{
    int clipboard, total, time;

    public Node(int clipboard, int total, int time){
        this.clipboard = clipboard;
        this.total = total;
        this.time = time;
    }
}

public class Main {
    public static int s;
    public static boolean[][] visited = new boolean[1001][1001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        s = Integer.parseInt(br.readLine());
        BFS();
    }

    public static void BFS(){
        Queue<Node> q = new LinkedList<>();
        q.offer(new Node(0, 1, 0));
        visited[0][1] = true;

        while(!q.isEmpty()){
            Node cur = q.poll();

            if(cur.total == s){
                System.out.println(cur.time);
                return;
            }

            q.offer(new Node(cur.total, cur.total, cur.time+1));

            if(cur.clipboard != 0 && cur.total + cur.clipboard <= s && !visited[cur.clipboard][cur.total + cur.clipboard]){
                q.offer(new Node(cur.clipboard, cur.total + cur.clipboard, cur.time + 1));
                visited[cur.clipboard][cur.total + cur.clipboard] = true;
            }
            if(cur.total >= 1 && !visited[cur.clipboard][cur.total - 1]){
                q.offer(new Node(cur.clipboard, cur.total - 1, cur.time + 1));
                visited[cur.clipboard][cur.total - 1] = true;
            }
        }
    }
}
