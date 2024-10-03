//https://www.acmicpc.net/problem/2056

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
            int num = Integer.parseInt(st.nextToken());
            for(int j=0; j<num; ++j){
                int a = Integer.parseInt(st.nextToken());
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
            ans[i] = time[i];
            if (arr[i] == 0)
                q.offer(i);
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

        System.out.println(Arrays.stream(ans).max().getAsInt());
    }
}
