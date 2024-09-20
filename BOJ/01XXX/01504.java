//https://www.acmicpc.net/problem/1504

import java.io.*;
import java.util.*;

class Node implements Comparable<Node>{
    int to, cost;

    public Node(int to, int cost){
        this.to = to;
        this.cost = cost;
    }

    @Override
    public int compareTo(Node n){
        return this.cost - n.cost;
    }
}

public class Main {
    public static int INF = 2000000;
    public static int n, e;
    public static ArrayList<Node>[] list;
    public static int[] dist;
    public static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        e = Integer.parseInt(st.nextToken());

        list = new ArrayList[n+1];
        dist = new int[n+1];
        visited = new boolean[n+1];
        for(int i=1; i<=n; ++i)
            list[i] = new ArrayList<>();

        for(int i=0; i<e; ++i){
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            list[a].add(new Node(b, c));
            list[b].add(new Node(a, c));
        }
        st = new StringTokenizer(br.readLine());
        int v1 = Integer.parseInt(st.nextToken());
        int v2 = Integer.parseInt(st.nextToken());

        int dist1 = 0, dist2 = 0;
        dist1 += dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, n);
        dist2 += dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, n);

        int ans = 0;
        if(dist1 >= INF && dist2 >= INF)
            ans = -1;
        else
            ans = Math.min(dist1, dist2);

        System.out.println(ans);
    }

    public static int dijkstra(int start, int end){
        Arrays.fill(visited, false);
        Arrays.fill(dist, INF);
        
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(start, 0));
        dist[start] = 0;

        while(!pq.isEmpty()){
            Node n = pq.poll();
            if(visited[n.to])
                continue;
            visited[n.to] = true;
            for(Node x : list[n.to])
                if(dist[x.to] > n.cost + x.cost) {
                    dist[x.to] = n.cost + x.cost;
                    pq.offer(new Node(x.to, dist[x.to]));
                }
        }
        return dist[end];
    }
}
