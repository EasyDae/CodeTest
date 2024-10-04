//https://www.acmicpc.net/problem/14567

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
        arr = new int[n+1];
        list = new ArrayList[n+1];
        for(int i=1; i<=n; ++i)
            list[i] = new ArrayList<>();

        for(int i=0; i<m; ++i){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            list[a].add(b);
            arr[b]++;
        }

        BFS();
    }

    public static void BFS(){
        Queue<Integer> q = new LinkedList<>();
        int[] ans = new int[n+1];
        for(int i=1; i<=n; ++i)
            if (arr[i] == 0) {
                q.offer(i);
                ans[i] = 1;
            }

        while(!q.isEmpty()){
            int cur = q.poll();

            for(int x : list[cur]){
                arr[x]--;
                if(arr[x] == 0) {
                    q.offer(x);
                    ans[x] = ans[cur]+1;
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        for(int i=1; i<=n; ++i)
            sb.append(ans[i]).append(' ');

        System.out.println(sb);
    }
}
