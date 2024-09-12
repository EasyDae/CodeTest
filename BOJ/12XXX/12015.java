//https://www.acmicpc.net/problem/12015

import java.io.*;
import java.util.*;

public class Main {
    public static int[] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] input = new int[n];
        int[] arr = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; ++i)
            input[i] = Integer.parseInt(st.nextToken());

        arr[0] = input[0];
        int idx = 1;
        for(int i=1; i<n; ++i){
            int num = input[i];

            if(arr[idx-1] < num){
                arr[idx] = num;
                idx++;
            }
            else{
                int left = 0, right = idx;
                while(left < right){
                    int mid = (left + right)/2;

                    if(arr[mid] < num)
                        left = mid + 1;
                    else
                        right = mid;
                }

                arr[left] = num;
            }
        }

        System.out.println(idx);
    }
}
