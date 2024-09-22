//https://www.acmicpc.net/problem/9019

import java.io.*;
import java.util.*;

public class Main {
    public static int[][] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int t = Integer.parseInt(br.readLine());
        for(int i=0; i<t; ++i){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            Queue<Integer> q = new LinkedList<>();
            boolean[] visited = new boolean[10000];
            String[] ans = new String[10000];

            q.offer(a);
            visited[a] = true;
            Arrays.fill(ans, "");

            while(!q.isEmpty() && !visited[b]){
                int cur = q.poll();

                int D = (2 * cur) % 10000;
                int S = (cur + 9999) % 10000;
                int L = cur / 1000 + (cur % 1000) * 10;
                int R = cur / 10 + (cur % 10) * 1000;

                if(!visited[D]){
                    q.offer(D);
                    visited[D] = true;
                    ans[D] = ans[cur] + 'D';
                }

                if(!visited[S]){
                    q.offer(S);
                    visited[S] = true;
                    ans[S] = ans[cur] + 'S';
                }

                if(!visited[L]){
                    q.offer(L);
                    visited[L] = true;
                    ans[L] = ans[cur] + 'L';
                }

                if(!visited[R]){
                    q.offer(R);
                    visited[R] = true;
                    ans[R] = ans[cur] + 'R';
                }
            }

            System.out.println(ans[b]);
        }
    }
}
