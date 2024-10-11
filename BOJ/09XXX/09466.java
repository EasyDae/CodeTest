//https://www.acmicpc.net/problem/9466

import java.io.*;
import java.util.*;

public class Main {
    public static int[] arr;
    public static boolean[] visited, finished;
    public static int n, cnt;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());
        for(int t=0; t<T; ++t){
            cnt = 0;
            n = Integer.parseInt(br.readLine());
            visited = new boolean[n+1];
            finished = new boolean[n+1];
            arr = new int[n+1];

            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int i=1; i<=n; ++i)
                arr[i] = Integer.parseInt(st.nextToken());

            for(int i=1; i<=n; ++i)
                if(!finished[i])
                    DFS(i);

            sb.append(n-cnt).append('\n');
        }

        System.out.println(sb);
    }

    public static void DFS(int idx){
        if(visited[idx]){
            finished[idx] = true;
            cnt++;
        } else visited[idx] = true;

        if(!finished[arr[idx]])
            DFS(arr[idx]);

        visited[idx] = false;
        finished[idx] = true;
    }
}
