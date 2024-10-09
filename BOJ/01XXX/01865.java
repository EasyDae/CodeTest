//https://www.acmicpc.net/problem/1865

import java.io.*;
import java.util.*;

class Node{
    int to, cost;

    public Node(int to, int cost){
        this.to = to;
        this.cost = cost;
    }
}

public class Main {
    public static int n, m, w, INF = 987654321;
    public static int[] dist;
    public static ArrayList<Node>[] list;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());
        for(int t=0; t<T; ++t){
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            w = Integer.parseInt(st.nextToken());

            dist = new int[n+1];
            list = new ArrayList[n+1];
            for(int i=1; i<=n; ++i)
                list[i] = new ArrayList<>();

            for(int i=0; i<m+w; ++i){
                st = new StringTokenizer(br.readLine());
                int from = Integer.parseInt(st.nextToken());
                int to = Integer.parseInt(st.nextToken());
                int cost = Integer.parseInt(st.nextToken());

                if(i<m){
                    list[from].add(new Node(to, cost));
                    list[to].add(new Node(from, cost));
                }
                else
                    list[from].add(new Node(to, -cost));
            }

            sb.append(bellmanford() ? "YES\n" : "NO\n");
        }
        System.out.println(sb);
    }

    private static boolean bellmanford() {
        Arrays.fill(dist, INF);
        dist[1] = 0;
        boolean flag = false;

        for(int i=1; i<=n; ++i){
            flag = false;

            for(int j=1; j<=n; ++j){
                for(Node x : list[j]){
                    if(dist[x.to] > dist[j] + x.cost){
                        dist[x.to] = dist[j] + x.cost;
                        flag = true;
                    }
                }
            }

            if(!flag)
                break;
        }

        if(flag)
            for(int i=1; i<=n; ++i)
                for(Node x : list[i])
                    if(dist[x.to] > dist[i] + x.cost)
                        return true;
        return false;
    }
}
