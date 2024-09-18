//https://www.acmicpc.net/problem/10282

import java.io.*;
import java.util.*;

class Node implements Comparable<Node>{
    int depend;
    int time;

    public Node(int depend, int time){
        this.depend = depend;
        this.time = time;
    }

    @Override
    public int compareTo(Node n){
        return this.time - n.time;
    }
}

public class Main {
    public static List<Node>[] list;
    public static int[] dist;
    public static boolean[] visited;
    public static int INF = 987654321;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());
        for(int t=0; t<T; ++t){
            st = new StringTokenizer(br.readLine());

            int n = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            list = new ArrayList[n+1];
            dist = new int[n+1];
            visited = new boolean[n+1];

            for(int i=1; i<=n; ++i){
                dist[i] = INF;
                list[i] = new ArrayList<>();
            }

            for(int i=0; i<d; ++i){
                st = new StringTokenizer(br.readLine());

                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                int s = Integer.parseInt(st.nextToken());

                list[b].add(new Node(a, s));
            }

            dijkstra(c);

            int cnt = 0, time = 0;
            for(int i=1; i<=n; ++i){
                if(dist[i] != INF){
                    cnt++;
                    time = Math.max(time, dist[i]);
                }
            }

            System.out.println(cnt + " " + time);
        }
    }

    public static void dijkstra(int start){
        Queue<Node> pq = new PriorityQueue<>();

        dist[start] = 0;
        pq.offer(new Node(start, 0));

        while(!pq.isEmpty()){
            int cur = pq.poll().depend;

            if(!visited[cur])
                visited[cur] = true;

            for(Node x : list[cur]){
                if(dist[x.depend] > dist[cur] + x.time){
                    dist[x.depend] = dist[cur] + x.time;
                    pq.offer(new Node(x.depend, dist[x.depend]));
                }
            }
        }
    }
}
