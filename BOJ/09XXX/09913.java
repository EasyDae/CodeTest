//https://www.acmicpc.net/problem/9913

import java.io.*;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int ans = 0;

        int[] arr = new int[10001];
        for(int i=0; i<n; ++i){
            int input = Integer.parseInt(br.readLine());
            arr[input]++;
            ans = Math.max(ans, arr[input]);
        }

        System.out.print(ans);
    }
}
