//https://www.acmicpc.net/problem/16463

import java.io.*;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int day = 13, ans = 0;
        for(int i=2019; i<=n; ++i){
            for(int j=0; j<12; ++j){
                if(day % 7 == 4) ans++;
                day += month[j];

                if(j == 1 && (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0)))
                    day++;
            }
        }

        System.out.print(ans);
    }
}
