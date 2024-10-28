//https://www.acmicpc.net/problem/30890

import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());

        int lcm = LCM(x, y);
        int[] arr = new int[lcm+1];

        for(int i=0; i<=lcm; i+=lcm/x)
            arr[i] += 1;
        for(int i=0; i<=lcm; i+=lcm/y)
            arr[i] += 2;

        StringBuilder sb = new StringBuilder();
        for(int i=1; i<=lcm; ++i)
            if(arr[i] != 0)
                sb.append(arr[i]);

        System.out.print(sb);
    }

    public static int GCD(int a, int b){
        if(b == 0)
            return a;
        else
            return GCD(b, a%b);
    }

    public static int LCM(int a, int b){
        return a*b/GCD(a,b);
    }
}
