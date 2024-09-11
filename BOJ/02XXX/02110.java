//https://www.acmicpc.net/problem/2110

import java.io.*;
import java.util.*;

public class Main {
    public static int[] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        arr = new int[n];
        for(int i=0; i<n; ++i)
            arr[i] = Integer.parseInt(br.readLine());

        Arrays.sort(arr);

        int left = 1, right = arr[n-1] - arr[0] + 1;
        while(left < right){
            int mid = (left + right)/2;

            if(check(mid) < c)
                right = mid;
            else
                left = mid + 1;
        }

        System.out.println(left - 1);
    }

    public static int check(int a){
        int cnt = 1;
        int lastloc = arr[0];

        for(int i=1; i<arr.length; ++i){
            if(arr[i] - lastloc >= a){
                cnt++;
                lastloc = arr[i];
            }
        }

        return cnt;
    }
}
