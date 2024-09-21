//https://www.acmicpc.net/problem/1915

import java.io.*;
import java.util.*;

public class Main {
    public static int[][] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        arr = new int[n][m];

        int len = 0;
        for(int i=0; i<n; ++i){
            String input = br.readLine();
            for(int j=0; j<m; ++j) {
                arr[i][j] = Character.getNumericValue(input.charAt(j));
                if(arr[i][j] == 1 && len == 0) len = 1;
                if(i>0 && j > 0)
                    if(arr[i-1][j] > 0 && arr[i][j-1] > 0 && arr[i-1][j-1] > 0 && arr[i][j] == 1){
                        arr[i][j] = Math.min(arr[i-1][j], Math.min(arr[i-1][j-1], arr[i][j-1]))+1;
                        len = Math.max(len, arr[i][j]);
                    }
            }
        }

        System.out.println(len * len);
    }
}
