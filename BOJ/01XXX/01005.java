//https://www.acmicpc.net/problem/1005

import java.io.*;
import java.util.*;

public class Main{
    public static ArrayList<Integer>[] list;
    public static int[] time, cnt;
    public static int n, k, w;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());
        for(int t=0; t<T; ++t){
            StringTokenizer st = new StringTokenizer(br.readLine());

            n = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());

            time = new int[n+1];
            cnt = new int[n+1];
            list = new ArrayList[n+1];
            for(int i=0; i<=n; ++i)
                list[i] = new ArrayList<>();

            st = new StringTokenizer(br.readLine());
            for(int i=1; i<=n; ++i)
                time[i] = Integer.parseInt(st.nextToken());

            for(int i=0; i<k; ++i){
                st = new StringTokenizer(br.readLine());

                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());

                list[a].add(b);
                cnt[b]++;
            }

            w = Integer.parseInt(br.readLine());
            BFS();
        }
    }

    public static void BFS(){
        Queue<Integer> q = new LinkedList<>();
        int[] ans = new int[n+1];

        for(int i=1; i<=n; ++i) {
            ans[i] = time[i];
            if (cnt[i] == 0)
                q.offer(i);
        }

        while(!q.isEmpty()){
            int cur = q.poll();

            for(var x : list[cur]){
                ans[x] = Math.max(ans[x], ans[cur] + time[x]);
                cnt[x]--;

                if(cnt[x] == 0)
                    q.offer(x);
            }
        }

        System.out.println(ans[w]);
    }
}
