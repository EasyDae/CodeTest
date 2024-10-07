//https://www.acmicpc.net/problem/11779

import java.io.*;
import java.util.*;

class City implements Comparable<City>{
    int to, cost;

    public City(int to, int cost){
        this.to = to;
        this.cost = cost;
    }

    @Override
    public int compareTo(City c){
        return this.cost - c.cost;
    }
}

public class Main{
    public static int n, m, start, end;
    public static int[] dist, prev;
    public static ArrayList<City>[] list;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());

        dist = new int[n+1];
        prev = new int[n+1];
        Arrays.fill(dist, Integer.MAX_VALUE);

        list = new ArrayList[n+1];
        for(int i=1; i<=n; ++i)
            list[i] = new ArrayList<>();

        for(int i=0; i<m; ++i){
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());

            list[from].add(new City(to, cost));
        }

        st = new StringTokenizer(br.readLine());
        start = Integer.parseInt(st.nextToken());
        end = Integer.parseInt(st.nextToken());

        dijkstra();
        StringBuilder sb = new StringBuilder();
        sb.append(dist[end]).append('\n');

        int cnt = 1;
        Stack<Integer> stk = new Stack<>();
        stk.push(end);
        while(prev[end] != 0){
            cnt++;
            stk.push(prev[end]);
            end = prev[end];
        }
        sb.append(cnt).append('\n');

        while(!stk.isEmpty())
            sb.append(stk.pop()).append(' ');

        System.out.println(sb);
    }

    private static void dijkstra() {
        PriorityQueue<City> q = new PriorityQueue<>();
        q.offer(new City(start, 0));
        dist[start] = 0;

        while(!q.isEmpty()){
            City cur = q.poll();
            if(dist[cur.to] < cur.cost)
                continue;

            for(City x : list[cur.to]){
                if(dist[x.to] > dist[cur.to] + x.cost){
                    dist[x.to] = dist[cur.to] + x.cost;
                    prev[x.to] = cur.to;
                    q.offer(new City(x.to, dist[x.to]));
                }
            }
        }
    }
}
