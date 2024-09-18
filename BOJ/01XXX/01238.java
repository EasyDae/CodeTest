//https://www.acmicpc.net/problem/1238

import java.io.*;
import java.util.*;

class Node implements Comparable<Node>{
    int to;
    int time;

    public Node(int to, int time){
        this.to = to;
        this.time = time;
    }

    @Override
    public int compareTo(Node n){
        return this.time - n.time;
    }
}

public class Main {
    public static ArrayList<Node>[] list, rlist;
    public static int[] dist, rdist;
    public static boolean[] visited;
    public static int INF = 987654321;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        list = new ArrayList[n+1];
        rlist = new ArrayList[n+1];
        dist = new int[n+1];
        rdist = new int[n+1];

        for(int i=1; i<=n; ++i){
            dist[i] = INF;
            rdist[i] = INF;
            list[i] = new ArrayList<>();
            rlist[i] = new ArrayList<>();
        }

        for(int i=0; i<m; ++i){
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int t = Integer.parseInt(st.nextToken());

            list[a].add(new Node(b, t));
            rlist[b].add(new Node(a, t));
        }

        dijkstra(list, dist, x);
        dijkstra(rlist, rdist, x);

        int max = 0;
        for(int i=1; i<=n; ++i)
            max = Math.max(max, dist[i] + rdist[i]);

        System.out.print(max);
    }

    public static void dijkstra(ArrayList<Node>[] arr, int[] dist, int start){
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(start, 0));
        dist[start] = 0;

        while(!pq.isEmpty()){
            Node n = pq.poll();
            for(Node next : arr[n.to]){
                if(dist[next.to] > dist[n.to] + next.time){
                    dist[next.to] = dist[n.to] + next.time;
                    pq.offer(new Node(next.to, dist[next.to]));
                }
            }
        }
    }
}
