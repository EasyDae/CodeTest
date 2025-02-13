//https://www.acmicpc.net/problem/31403

import java.io.*;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String a = br.readLine();
        String b = br.readLine();
        String c = br.readLine();

        sb.append(Integer.parseInt(a) + Integer.parseInt(b) - Integer.parseInt(c)).append('\n');
        sb.append(Integer.parseInt(a + b) - Integer.parseInt(c));

        System.out.print(sb);
    }
}
