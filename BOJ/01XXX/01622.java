//https://www.acmicpc.net/problem/1622

import java.io.*;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        while(true){
            String a = br.readLine();
            if(a==null){
                System.out.print(sb);
                return;
            }
            String b = br.readLine();
            int[] arr1 = new int[26];
            int[] arr2 = new int[26];
            for(int i=0; i<a.length(); ++i)
                arr1[a.charAt(i)-'a']++;
            for(int i=0; i<b.length(); ++i)
                arr2[b.charAt(i)-'a']++;

            for(int i=0; i<26; ++i)
                for(int j=0; j<(Math.min(arr1[i], arr2[i])); ++j)
                    sb.append((char)('a' + i));
            sb.append('\n');
        }
    }
}
