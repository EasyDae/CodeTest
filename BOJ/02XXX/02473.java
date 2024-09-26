//https://www.acmicpc.net/problem/2473

import java.io.*;
import java.util.*;

public class Main {
    public static long[] arr;
    public static int[] ans = new int[3];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        arr = new long[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; ++i)
            arr[i] = Long.parseLong(st.nextToken());

        Arrays.sort(arr);


        long max = 3000000000L;
        for(int i=0; i<n-2; ++i){
            int left = i + 1, right = n - 1;
            while(left < right){
                long sum = arr[i] + arr[left] + arr[right];
                if(max > Math.abs(sum)){
                    ans[0] = i;
                    ans[1] = left;
                    ans[2] = right;
                    max = Math.abs(sum);
                }

                if(sum > 0)
                    right--;
                else if(sum < 0)
                    left++;
                else
                    break;
            }
        }

        Arrays.sort(ans);
        System.out.println(arr[ans[0]] + " " + arr[ans[1]] + " " + arr[ans[2]]);
    }
}
