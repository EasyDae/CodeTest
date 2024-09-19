//https://www.acmicpc.net/problem/13905

import java.io.*;
import java.util.*;

class Node implements Comparable<Node>{
    int from, to, weight;

    public Node(int from, int to, int weight){
        this.from = from;
        this.to = to;
        this.weight = weight;
    }

    @Override
    public int compareTo(Node n){
        return n.weight - this.weight;
    }
}

public class Main {
    public static int n, m, s, e;
    public static int[] parent;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        parent = new int[n+1];
        for(int i=1; i<=n; ++i)
            parent[i] = i;

        st = new StringTokenizer(br.readLine());
        s = Integer.parseInt(st.nextToken());
        e = Integer.parseInt(st.nextToken());

        PriorityQueue<Node> pq = new PriorityQueue<>();
        for(int i=0; i<m; ++i){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            pq.offer(new Node(a, b, c));
        }

        int ans = 0;
        while(!pq.isEmpty()){
            Node tmp = pq.poll();
            int a = find(tmp.from);
            int b = find(tmp.to);

            if(find(s) != find(e)){
                union(a, b);
                ans = tmp.weight;
            }
            else
                break;
        }
        if(find(s) != find(e))
            ans = 0;
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
