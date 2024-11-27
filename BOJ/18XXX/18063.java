//https://www.acmicpc.net/problem/18063

import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        int total = -(n-1) * c;
        for(int i=0; i<n; ++i){
            String time = br.readLine();
            total += (time.charAt(0)-'0') * 60 + (time.charAt(2)-'0') * 10 + (time.charAt(3)-'0');
        }
        int hour = total/3600;
        total%=3600;
        int min = total/60;
        total%=60;
        int sec = total;

        System.out.printf("%02d:%02d:%02d", hour, min, sec);
    }
}
