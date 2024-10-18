//https://www.acmicpc.net/problem/9342

import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());
        String str = "[A-F]?A+F+C+[A-F]?$";

        StringBuilder sb = new StringBuilder();
        while(T --> 0) {
            sb.append(br.readLine().matches(str) ? "Infected!\n" : "Good\n");
        }
        System.out.print(sb);
    }
}
