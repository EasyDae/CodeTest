//https://www.acmicpc.net/problem/14626

import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        int sum = 0;
        int idx = 0;
        for(int i=0; i<input.length(); ++i){
            char ch = input.charAt(i);
            if(ch != '*')
                sum += i%2 == 0 ? ch-'0' : (ch-'0') * 3;
            else idx = i;
        }
        int ans = 0;
        while(true){
            if(idx%2 == 0) {
                if ((sum + ans) % 10 == 0) {
                    System.out.print(ans);
                    break;
                }
                else ans++;
            } else{
                if ((sum + ans * 3) % 10 == 0) {
                    System.out.print(ans);
                    break;
                }
                else ans++;
            }
        }
    }
}
