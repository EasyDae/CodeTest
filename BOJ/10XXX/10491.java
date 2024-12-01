//https://www.acmicpc.net/problem/10491

import java.io.*;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String input;
        String regex = "(?i).*problem.*";
        while((input = br.readLine()) != null)
            bw.write(input.matches(regex) ? "yes\n" : "no\n");

        bw.flush();
    }
}
