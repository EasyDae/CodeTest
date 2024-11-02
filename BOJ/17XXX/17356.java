//https://www.acmicpc.net/problem/17356

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());

        double m = (b-a)/400.0;
        System.out.print(1/(1+Math.pow(10, m)));
    }
}
