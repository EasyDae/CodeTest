//https://www.acmicpc.net/problem/2458

import java.io.*;
import java.util.*;

public class Main {
    public static boolean[][] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        arr = new boolean[n+1][n+1];

        for(int i=0; i<m; ++i){
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            arr[a][b] = true;
        }

        for(int k=1; k<=n; ++k)
            for(int i=1; i<=n; ++i)
                for(int j=1; j<=n; ++j)
                    if(arr[i][k] && arr[k][j])
                        arr[i][j] = true;

        int ans = 0;
        for(int i=1; i<=n; ++i){
            int cnt = 0;
            for(int j=1; j<=n; ++j) {
                if(arr[i][j] || arr[j][i])
                    cnt++;
            }
            if(cnt == n-1)
                ans++;
        }

        System.out.println(ans);
    }
}
