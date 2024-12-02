//https://www.acmicpc.net/problem/24090

import java.io.*;
import java.util.*;

public class Main{
    public static int k;
    public static int cnt;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        int[] arr = new int[n];

        st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; ++i)
            arr[i] = Integer.parseInt(st.nextToken());

        quickSort(arr, 0, n-1);
        if(cnt < k)
            System.out.print(-1);
    }

    public static void quickSort(int[] arr, int start, int end){
        if(start < end){
            int mid = partition(arr, start, end);
            quickSort(arr, start, mid-1);
            quickSort(arr, mid+1, end);
        }
    }

    public static int partition(int[] arr, int start, int end){
        int pivot = arr[end];
        int idx = start - 1;
        for(int i=start; i<end; ++i)
            if(arr[i] <= pivot)
                swap(arr, ++idx, i);

        if(idx+1 != end)
            swap(arr, idx+1, end);

        return idx+1;
    }

    public static void swap(int[] arr, int a, int b){
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
        cnt++;

        if(cnt == k)
            System.out.print(arr[a] + " " + arr[b]);
    }
}
