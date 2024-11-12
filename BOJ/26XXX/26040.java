//https://www.acmicpc.net/problem/26040

import java.io.*;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String input = br.readLine();
        boolean[] check = new boolean[26];

        char[] ch = br.readLine().toCharArray();
        for(char x : ch)
            if(x != ' ')
                check[x-'A'] = true;

        StringBuilder sb = new StringBuilder();
        for(int i=0; i<input.length(); ++i){
            if((input.charAt(i) >= 'A' && input.charAt(i) <= 'Z') && (check[input.charAt(i)-'A']))
                sb.append((char)(input.charAt(i) + 32));
            else
                sb.append(input.charAt(i));
        }

        System.out.print(sb);
    }
}
