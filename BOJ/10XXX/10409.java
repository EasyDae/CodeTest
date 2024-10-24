//https://www.acmicpc.net/problem/10409

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int t = Integer.parseInt(st.nextToken());

        int sum = 0, cnt = 0;
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; ++i){
            int num = Integer.parseInt(st.nextToken());
            sum += num;
            if(sum > t){
                System.out.print(cnt);
                return;
            }
            else
                cnt++;
        }

        System.out.print(cnt);
    }
}
