//https://www.acmicpc.net/problem/17298

import java.io.*;
import java.util.*;

public class Main {
    public static int[][] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        Stack<Integer> stk = new Stack<>();

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; ++i)
            arr[i] = Integer.parseInt(st.nextToken());

        for(int i=0; i<n; ++i){
            while(!stk.isEmpty() && arr[stk.peek()] < arr[i])
                arr[stk.pop()] = arr[i];

            stk.push(i);
        }

        while(!stk.isEmpty())
            arr[stk.pop()] = -1;

        for(int i=0; i<n; ++i)
            sb.append(arr[i]).append(" ");

        System.out.println(sb);
    }
}
