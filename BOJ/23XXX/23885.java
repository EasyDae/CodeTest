//https://www.acmicpc.net/problem/23885

import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int s1 = Integer.parseInt(st.nextToken());
        int e1 = Integer.parseInt(st.nextToken());
        boolean bs1 = s1 % 2 == 0;
        boolean be1 = e1 % 2 == 0;

        st = new StringTokenizer(br.readLine());
        int s2 = Integer.parseInt(st.nextToken());
        int e2 = Integer.parseInt(st.nextToken());
        boolean bs2 = s2 % 2 == 0;
        boolean be2 = e2 % 2 == 0;

        String output;
        if(n == 1 || m == 1){
            if(s1 == s2 && e1 == e2)
                output = "YES";
            else output = "NO";
        }
        else if(bs1 != be1 && bs2 != be2)
            output = "YES";
        else if(bs1 == be1 && bs2 == be2)
            output = "YES";
        else output = "NO";

        System.out.print(output);
    }
}
