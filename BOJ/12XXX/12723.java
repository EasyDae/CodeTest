//https://www.acmicpc.net/problem/12723

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());
        for(int t=1; t<=T; ++t){
            int n = Integer.parseInt(br.readLine());
            Integer[] arr1 = new Integer[n];
            Integer[] arr2 = new Integer[n];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int i=0; i<n; ++i)
                arr1[i] = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            for(int i=0; i<n; ++i)
                arr2[i] = Integer.parseInt(st.nextToken());

            Arrays.sort(arr1);
            Arrays.sort(arr2, Collections.reverseOrder());

            int ans = 0;
            for(int i=0; i<n; ++i)
                ans += arr1[i] * arr2[i];

            sb.append("Case #").append(t).append(": ").append(ans).append('\n');
        }
        System.out.print(sb);
    }
}
