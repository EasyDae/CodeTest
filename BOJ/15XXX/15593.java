//https://www.acmicpc.net/problem/15593

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] safe = new int[1001];
        int[][] arr = new int[n][2];
        int total = 0;
        for(int i=0; i<n; ++i){
            StringTokenizer st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken());

            for(int j=arr[i][0]; j<arr[i][1]; ++j){
                if(safe[j] == 0)
                    total++;
                safe[j]++;
            }
        }

        int min = 1000;
        for(int i=0; i<n; ++i){
            int cnt = 0;
            for(int j=arr[i][0]; j<arr[i][1]; ++j)
                if(safe[j]<=1)
                    cnt++;
            min = Math.min(min, cnt);
        }

        System.out.println(total - min);
    }
}
