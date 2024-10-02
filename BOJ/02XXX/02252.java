//https://www.acmicpc.net/problem/2252

import java.io.*;
import java.util.*;

public class Main{
    public static ArrayList<Integer>[] list;
    public static StringBuilder sb = new StringBuilder();
    public static int[] cnt;
    public static int n, m;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        cnt = new int[n+1];
        list = new ArrayList[n+1];
        for(int i=0; i<=n; ++i)
            list[i] = new ArrayList<>();

        for(int i=0; i<m; ++i){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            list[a].add(b);
            cnt[b]++;
        }

        BFS();
        System.out.println(sb);
    }

    public static void BFS(){
        Queue<Integer> q = new LinkedList<>();

        for(int i=1; i<=n; ++i)
            if(cnt[i] == 0)
                q.offer(i);

        while(!q.isEmpty()){
            int cur = q.poll();
            sb.append(cur + " ");
            for(var x : list[cur]){
                cnt[x]--;
                if(cnt[x] == 0)
                    q.offer(x);
            }
        }
    }
}
