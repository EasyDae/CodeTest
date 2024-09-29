//https://www.acmicpc.net/problem/13144

import java.io.*;
import java.util.*;

public class Main {
    public static int[] arr;
    public static int[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        arr = new int[n];
        visited = new int[100001];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; ++i)
            arr[i] = Integer.parseInt(st.nextToken());

        int left = 0, right = 0;
        long ans = 0;
        while(left < n) {
            while (right < n && visited[arr[right]] == 0){
                visited[arr[right++]]++;
            }

            ans += right - left;
            visited[arr[left++]]--;
        }

        System.out.println(ans);
    }
}
