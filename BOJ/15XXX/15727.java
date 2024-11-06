//https://www.acmicpc.net/problem/15727

import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int l = Integer.parseInt(br.readLine());
        System.out.print(l%5 == 0 ? l/5 : l/5+1);
    }
}
