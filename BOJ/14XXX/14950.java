//https://www.acmicpc.net/problem/14950

import java.io.*;
import java.util.*;

class Node implements Comparable<Node>{
    int from;
    int to;
    int cost;

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

public class Main{
    public static int[] parent;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int t = Integer.parseInt(st.nextToken());

        parent = new int[n + 1];
        for(int i=1; i<=n; ++i)
            parent[i] = i;

        Queue<Node> pq = new PriorityQueue<>();
        for(int i=0; i<m; ++i){
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            pq.add(new Node(a, b, c));
        }

        int cnt = 0, total = 0;
        while(!pq.isEmpty()){
            Node tmp = pq.poll();
            int a = tmp.from;
            int b = tmp.to;

            if(find(a) != find(b)){
                total += tmp.cost + (t * cnt);
                union(a, b);
                cnt++;
            }
        }

        System.out.println(total);
    }

    public static int find(int x){
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    public static void union(int a, int b){
        a = find(a);
        b = find(b);

        parent[b] = a;
    }
}
