//https://www.acmicpc.net/problem/28282

import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long x = Long.parseLong(st.nextToken());
        long k = Long.parseLong(st.nextToken());

        st = new StringTokenizer(br.readLine());
        long[] left = new long[10001];
        for(long i=0; i<x; ++i)
            left[Integer.parseInt(st.nextToken())]++;

        long[] right = new long[10001];
        for(long i=0; i<x; ++i)
            right[Integer.parseInt(st.nextToken())]++;

        long sum = x * x;
        for(int i=1; i<=k; ++i)
            sum -= left[i] * right[i];

        System.out.print(sum);
    }
}
