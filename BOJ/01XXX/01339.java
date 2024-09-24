//https://www.acmicpc.net/problem/1339

import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[26];

        for(int i=0; i<n; ++i){
            String input = br.readLine();
            for(int j=0; j<input.length(); ++j){
                char c = input.charAt(j);
                arr[c-'A'] += (int)Math.pow(10, input.length() - 1 - j);
            }
        }

        Arrays.sort(arr);

        int ans = 0, num = 9;
        for(int i=25; i>=0; --i){
            if(arr[i] == 0){
                System.out.println(ans);
                return;
            }
            ans += arr[i] * num;
            num--;
        }
    }
}
