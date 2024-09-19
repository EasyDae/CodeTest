//https://www.acmicpc.net/problem/1368

import java.io.*;
import java.util.*;

class Node implements Comparable<Node>{
    int from, to, cost;

    public Node(int from, int to, int cost){
        this.from = from;
        this.to = to;
        this.cost = cost;
    }

    @Override
    public int compareTo(Node n){
        return this.cost - n.cost;
    }
}

public class Main {
    public static int n;
    public static int[] cost;
    public static int[] parent;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        n = Integer.parseInt(br.readLine());
        cost = new int[n+1];
        parent = new int[n+1];
        for(int i=1; i<=n; ++i) {
            cost[i] = Integer.parseInt(br.readLine());
            parent[i] = i;
        }

        PriorityQueue<Node> pq = new PriorityQueue<>();
        for(int i=1; i<=n; ++i){
            st = new StringTokenizer(br.readLine());
            for(int j=1; j<=n; ++j){
                int num = Integer.parseInt(st.nextToken());
                if(i==j)
                    pq.offer(new Node(0, i, cost[i]));
                else
                    pq.offer(new Node(i, j, num));
            }
        }

        int ans = 0;
        while(!pq.isEmpty()){
            Node tmp = pq.poll();
            int a = find(tmp.from);
            int b = find(tmp.to);

            if(a != b){
                union(a, b);
                ans += tmp.cost;
            }
        }

        System.out.println(ans);
    }

    public static void union(int a, int b){
        a = find(a);
        b = find(b);
        parent[b] = a;
    }

    public static int find(int a){
        if(parent[a] == a)
            return a;

        return parent[a] = find(parent[a]);
    }
}
