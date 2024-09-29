//https://www.acmicpc.net/problem/15961

import java.io.*;
import java.util.*;

public class Main {
    public static int[] arr;
    public static int[] visited;
    public static int n, d, k, c;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());

        arr = new int[n];
        visited = new int[d+1];

        for(int i=0; i<n; ++i)
            arr[i] = Integer.parseInt(br.readLine());

        int cnt = 0, coupon;
        for(int i=0; i<k; ++i){
            if(visited[arr[i]] == 0)
                cnt++;
            visited[arr[i]]++;
        }

        coupon = cnt;
        for(int i=1; i<=n; ++i){
            if(coupon <= cnt){
                if(visited[c] == 0)
                    coupon = cnt + 1;
                else
                    coupon = cnt;
            }

            visited[arr[i-1]]--;
            if(visited[arr[i-1]] == 0)
                cnt--;

            if(visited[arr[(i+k-1)%n]] == 0)
                cnt++;
            visited[arr[(i+k-1)%n]]++;
        }

        System.out.println(coupon);
    }
}
