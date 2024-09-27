//https://www.acmicpc.net/problem/7453

import java.io.*;
import java.util.*;

public class Main {
    public static int[][] arr;
    public static int[] ab;
    public static int[] cd;
    public static int INF = 987654321;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        arr = new int[4][n];
        ab = new int[n*n];
        cd = new int[n*n];

        for(int i=0; i<n; ++i){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j=0; j<4; ++j)
                arr[j][i] = Integer.parseInt(st.nextToken());
        }

        int idx = 0;
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j){
                ab[idx] = arr[0][i] + arr[1][j];
                cd[idx++] = arr[2][i] + arr[3][j];
            }

        Arrays.sort(ab);
        Arrays.sort(cd);

        int left = 0, right = n*n-1;
        long ans = 0;
        while(left < n*n && right >= 0){
            int sum = ab[left] + cd[right];
            if(sum < 0)
                left++;
            else if(sum > 0)
                right--;
            else{
                long lcnt = 1, rcnt = 1;
                while(left + 1 < n*n && ab[left] == ab[left + 1]){
                    lcnt++;
                    left++;
                }
                while(right - 1 >= 0 && cd[right] == cd[right - 1]){
                    rcnt++;
                    right--;
                }

                ans += lcnt * rcnt;
                left++;
            }
        }

        System.out.println(ans);
    }
}
