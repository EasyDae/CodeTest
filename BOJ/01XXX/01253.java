//https://www.acmicpc.net/problem/1253

import java.io.*;
import java.util.*;

public class Main {
    public static int[] arr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        arr = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; ++i)
            arr[i] = Integer.parseInt(st.nextToken());

        Arrays.sort(arr);

        int ans = 0;
        for(int i=0; i<n; ++i){
            int start = 0, end = n - 1;
            while(true){
                if(start == i)
                    start++;
                else if(end == i)
                    end--;

                if(start >= end)
                    break;

                if(arr[start] + arr[end] > arr[i])
                    end--;
                else if(arr[start] + arr[end] < arr[i])
                    start++;
                else{
                    ans++;
                    break;
                }
            }
        }

        System.out.println(ans);
    }
}
