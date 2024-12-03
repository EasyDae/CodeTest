//https://www.acmicpc.net/problem/14627

import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int s = Integer.parseInt(st.nextToken()), c = Integer.parseInt(st.nextToken());
        int[] arr = new int[s];
        long sum = 0;
        for(int i=0; i<s; ++i){
            arr[i] = Integer.parseInt(br.readLine());
            sum += arr[i];
        }

        long left = 1, right = 1000000000, len = 0;
        while(left <= right){
            long mid = (left + right)/2;
            int cnt = 0;
            for(int i=0; i<s; ++i)
                cnt += arr[i]/mid;

            if(cnt >= c){
                len = mid;
                left = mid + 1;
            }else right = mid - 1;
        }

        System.out.print(sum - (len * c));
    }
}
