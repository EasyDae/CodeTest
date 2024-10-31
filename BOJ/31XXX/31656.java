//https://www.acmicpc.net/problem/31656

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String input = br.readLine();

        char prev = input.charAt(0);
        sb.append(prev);
        for(int i=1; i<input.length(); ++i){
            char cur = input.charAt(i);
            if(cur == prev)
                continue;

            prev = cur;
            sb.append(cur);
        }

        System.out.print(sb);
    }
}
