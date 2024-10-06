//https://www.acmicpc.net/problem/10986

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] cnt = new int[m];

        st = new StringTokenizer(br.readLine());
        int sum = 0;
        for(int i=0; i<n; ++i){
            int num = Integer.parseInt(st.nextToken());
            sum = (sum + num) % m;
            cnt[sum]++;
        }

        long ans = cnt[0];
        for(int i=0; i<m; ++i)
            if(cnt[i] > 1)
                ans += (long)cnt[i] * (cnt[i]-1) / 2;

        System.out.println(ans);
    }
}
