//https://www.acmicpc.net/problem/15886

import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        String input = new StringBuilder(br.readLine()).reverse().toString();

        int ans = 0;
        char prev = 'E';
        for(int i=0; i<n; ++i){
            char ch = input.charAt(i);
            if(ch == 'W' && prev != 'W')
                ans++;
            prev = ch;
        }

        System.out.print(ans);
    }
}
