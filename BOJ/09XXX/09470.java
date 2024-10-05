//https://www.acmicpc.net/problem/9470

import java.io.*;
import java.util.*;

public class Main {
    public static ArrayList<Integer>[] list;
    public static int[] arr;
    public static int k, m, p;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());
        for(int t=0; t<T; ++t){
            StringTokenizer st = new StringTokenizer(br.readLine());

            k = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            p = Integer.parseInt(st.nextToken());

            arr = new int[m+1];
            list = new ArrayList[m+1];
            for(int i=1; i<=m; ++i)
                list[i] = new ArrayList<>();

            for(int i=0; i<p; ++i){
                st = new StringTokenizer(br.readLine());

                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());

                list[a].add(b);
                arr[b]++;
            }

            BFS();
        }
    }

    public static void BFS(){
        Queue<Integer> q = new LinkedList<>();
        int[] order = new int[m+1];
        int[] cnt = new int[m+1];

        for(int i=1; i<=m; ++i){
            if(arr[i] == 0){
                q.offer(i);
                order[i] = 1;
                cnt[i] = 1;
            }
        }

        int max = 0;
        while(!q.isEmpty()){
            int cur = q.poll();
            if(cnt[cur] > 1)
                order[cur]++;
            max = Math.max(max, order[cur]);

            for(int x : list[cur]){
                arr[x]--;
                if(arr[x] == 0)
                    q.offer(x);

                if(order[cur] == order[x])
                    cnt[x]++;
                else if(order[cur] > order[x]){
                    order[x] = order[cur];
                    cnt[x] = 1;
                }
            }
        }

        System.out.println(k + " " + max);
    }
}
