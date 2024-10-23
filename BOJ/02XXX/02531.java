//https://www.acmicpc.net/problem/2531

import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        int[] arr = new int[n];
        int[] visited = new int[m+1];

        for(int i=0; i<n; ++i){
            arr[i] = Integer.parseInt(br.readLine());
        }

        int cnt = 0;
        for(int i=0; i<k; ++i){
            if(visited[arr[i]] == 0)
                cnt++;
            visited[arr[i]]++;
        }

        int coup = cnt;
        for(int i=1; i<=n; ++i){
            if(coup <= cnt){
                if(visited[c] == 0)
                    coup = cnt + 1;
                else
                    coup = cnt;
            }

            visited[arr[i-1]]--;
            if(visited[arr[i-1]] == 0)
                cnt--;

            if(visited[arr[(k-1+i)%n]] == 0)
                cnt++;
            visited[arr[(k-1+i)%n]]++;
        }
        System.out.println(coup);
    }
}
