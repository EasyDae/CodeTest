//https://www.acmicpc.net/problem/2623

import java.io.*;
import java.util.*;

public class Main {
    public static ArrayList<Integer>[] list;
    public static int[] arr;
    public static int n, m;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        list = new ArrayList[n+1];
        arr = new int[n+1];

        for(int i=1; i<=n; ++i)
            list[i] = new ArrayList<>();

        for(int i=0; i<m; ++i){
            st = new StringTokenizer(br.readLine());
            int cnt = Integer.parseInt(st.nextToken());
            int prev = Integer.parseInt(st.nextToken());
            for(int j=1; j<cnt; ++j){
                int now = Integer.parseInt(st.nextToken());
                list[prev].add(now);
                arr[now]++;
                prev = now;
            }
        }

        BFS();
    }

    public static void BFS(){
        Queue<Integer> q = new LinkedList<>();
        ArrayList<Integer> ans = new ArrayList<>();

        for(int i=1; i<=n; ++i)
            if(arr[i] == 0)
                q.offer(i);

        while(!q.isEmpty()){
            int cur = q.poll();
            ans.add(cur);

            for(int x : list[cur]){
                arr[x]--;
                if(arr[x] == 0) {
                    q.offer(x);
                }
            }
        }

        if(ans.size() != n)
            System.out.println(0);
        else{
            StringBuilder sb = new StringBuilder();

            for(int x : ans)
                sb.append(x).append('\n');

            System.out.println(sb);
        }
    }
}
