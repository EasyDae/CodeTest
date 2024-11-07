//https://www.acmicpc.net/problem/25858

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());

        int[] arr = new int[n];
        int sum = 0;
        for(int i=0; i<n; ++i){
            arr[i] = Integer.parseInt(br.readLine());
            sum += arr[i];
        }

        int money = d/sum;
        for(int x : arr)
            sb.append(x * money).append('\n');

        System.out.print(sb);
    }
}
