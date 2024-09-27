//https://www.acmicpc.net/problem/1058

import java.io.*;

public class Main {
    public static int[][] arr;
    public static int INF = 987654321;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        arr = new int[n][n];

        for(int i=0; i<n; ++i){
            String input = br.readLine();
            for(int j=0; j<n; ++j)
                if(i!=j)
                    arr[i][j] = input.charAt(j) == 'Y' ? 1 : INF;
        }

        for(int k=0; k<n; ++k)
            for(int i=0; i<n; ++i)
                for(int j=0; j<n; ++j)
                    if(i!=j)
                        arr[i][j] = Math.min(arr[i][j], arr[k][j] + arr[i][k]);

        int max = 0;
        for(int i=0; i<n; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j)
                if(arr[i][j] == 2 || arr[i][j] == 1)
                    cnt++;

            max = Math.max(max, cnt);
        }

        System.out.println(max);
    }
}
