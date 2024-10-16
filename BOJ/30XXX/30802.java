//https://www.acmicpc.net/problem/30802

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[6];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<6; ++i)
            arr[i] = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        int p = Integer.parseInt(st.nextToken());

        int cnt = 0;
        for(int i=0; i<6; ++i){
            cnt += arr[i]/t;
            if(arr[i]%t != 0)
                cnt++;
        }

        String sb = String.valueOf(cnt) + '\n' + n / p + ' ' + n % p;
        System.out.println(sb);
    }
}
