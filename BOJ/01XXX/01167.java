//https://www.acmicpc.net/problem/1167

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
    public static int v, ans, node = 1;
    public static ArrayList<Node>[] list;
    public static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        v = Integer.parseInt(br.readLine());
        list = new ArrayList[v+1];
        for(int i = 1; i<= v; ++i)
            list[i] = new ArrayList<>();

        for(int i = 0; i < v; ++i){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            while(true){
                int b = Integer.parseInt(st.nextToken());
                if(b == -1)
                    break;
                int cost = Integer.parseInt(st.nextToken());
                list[a].add(new Node(b, cost));
            }
        }

        visited = new boolean[v +1];
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
                DFS(cur.to, sum + cur.cost);
                visited[cur.to] = true;
            }
        }
    }
}
