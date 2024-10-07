//https://www.acmicpc.net/problem/1967

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

public class Main{
    public static int n, ans, node = 1;
    public static ArrayList<Node>[] list;
    public static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        list = new ArrayList[n+1];
        for(int i=1; i<=n; ++i)
            list[i] = new ArrayList<>();

        for(int i=1; i<n; ++i){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());

            list[a].add(new Node(b, cost));
            list[b].add(new Node(a, cost));
        }

        visited = new boolean[n+1];
        DFS(1, 0);
        Arrays.fill(visited, false);
        DFS(node, 0);

        System.out.println(ans);
    }

    private static void DFS(int idx, int sum) {
        visited[idx] = true;
        if(ans < sum){
            ans = sum;
            node = idx;
        }

        for(int i=0; i<list[idx].size(); ++i){
            Node cur = list[idx].get(i);
            if(!visited[cur.to]){
                visited[cur.to] = true;
                DFS(cur.to, sum + cur.cost);
                visited[cur.to] = false;
            }
        }
    }
}
