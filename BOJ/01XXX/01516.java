//https://www.acmicpc.net/problem/1516

import java.io.*;
import java.util.*;

public class Main {
    public static ArrayList<Integer>[] list;
    public static int[] arr, time;
    public static int n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        list = new ArrayList[n+1];
        arr = new int[n+1];
        time = new int[n+1];
        for(int i=1; i<=n; ++i)
            list[i] = new ArrayList<>();

        for(int i=1; i<=n; ++i){
            StringTokenizer st = new StringTokenizer(br.readLine());
            time[i] = Integer.parseInt(st.nextToken());
            while(true){
                int a = Integer.parseInt(st.nextToken());
                if(a == -1)
                    break;
                list[a].add(i);
                arr[i]++;
            }
        }

        BFS();
    }

    public static void BFS(){
        Queue<Integer> q = new LinkedList<>();
        int[] ans = new int[n+1];
        for(int i=1; i<=n; ++i) {
            if (arr[i] == 0) {
                q.offer(i);
                ans[i] = time[i];
            }
        }

        while(!q.isEmpty()){
            int cur = q.poll();

            for(int x : list[cur]){
                ans[x] = Math.max(ans[x], ans[cur] + time[x]);
                arr[x]--;
                if(arr[x] == 0)
                    q.offer(x);
            }
        }

        StringBuilder sb = new StringBuilder();
        for(int i=1; i<=n; ++i)
            sb.append(ans[i]).append(' ');

        System.out.println(sb);
    }
}
