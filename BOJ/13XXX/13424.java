//https://www.acmicpc.net/problem/13424

import java.io.*;
import java.util.*;

public class Main {
    public static int INF = 987654321;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());
        for(int t=0; t<T; ++t){
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            int[][] arr = new int[n+1][n+1];
            for(int i=1; i<=n; ++i)
                for(int j=1; j<=n; ++j)
                    if(i!=j) arr[i][j] = INF;

            for(int i=0; i<m; ++i){
                st = new StringTokenizer(br.readLine());

                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                int c = Integer.parseInt(st.nextToken());

                arr[a][b] = arr[b][a] = c;
            }

            for(int l=1; l<=n; ++l)
                for(int i=1; i<=n; ++i)
                    for(int j=1; j<=n; ++j)
                        arr[i][j] = Math.min(arr[i][j], arr[i][l] + arr[l][j]);

            int k = Integer.parseInt(br.readLine());
            int[] friend = new int[k];
            st = new StringTokenizer(br.readLine());
            for(int i=0; i<k; ++i)
                friend[i] = Integer.parseInt(st.nextToken());

            int ans = -1, min = INF;
            for(int i=1; i<=n; ++i){
                int sum = 0;
                for(int j=0; j<k; ++j)
                    sum += arr[friend[j]][i];

                if(sum < min){
                    min = sum;
                    ans = i;
                }
            }

            System.out.println(ans);
        }
    }
}
