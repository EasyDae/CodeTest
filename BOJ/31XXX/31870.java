//https://www.acmicpc.net/problem/31870

import java.io.*;
import java.util.*;

public class Main{
    public static int n;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        int[] larr = new int[n];
        int[] rarr = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; ++i) {
            larr[i] = Integer.parseInt(st.nextToken());
            rarr[i] = larr[i];
        }
        System.out.print(Math.min(ascend(larr), descend(rarr)));
    }

    public static int ascend(int[] arr){
        int cnt = 0;
        while(true){
            boolean done = true;
            for(int i=0; i<n-1; ++i){
                if(arr[i] > arr[i+1]){
                    done = false;
                    int tmp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = tmp;
                    cnt++;
                }
            }
            if(done)
                break;
        }
        return cnt;
    }

    public static int descend(int[] arr){
        int cnt = 1;
        while(true){
            boolean done = true;
            for(int i=n-1; i>=1; --i){
                if(arr[i] > arr[i-1]){
                    done = false;
                    int tmp = arr[i];
                    arr[i] = arr[i-1];
                    arr[i-1] = tmp;
                    cnt++;
                }
            }
            if(done)
                break;
        }
        return cnt;
    }
}
