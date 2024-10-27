//https://www.acmicpc.net/problem/25775

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());
        String[] input = new String[n];

        int len = 0;
        for(int i=0; i<n; ++i) {
            input[i] = br.readLine();
            len = Math.max(len, input[i].length());
        }

        int[][] arr = new int[len][26];
        int[] max = new int[len];
        for(int i=0; i<n; ++i){
            int size = input[i].length();
            for(int j=0; j<size; ++j){
                char ch = input[i].charAt(j);
                arr[j][ch-'a']++;
                max[j] = Math.max(max[j], arr[j][ch-'a']);
            }
        }

        for(int i=0; i<len; ++i){
            sb.append(i+1).append(':');
            for(int j=0; j<26; ++j)
                if(arr[i][j] == max[i])
                    sb.append(' ').append((char)('a'+j));
            sb.append('\n');
        }

        System.out.println(sb);
    }
}
