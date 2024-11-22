//https://www.acmicpc.net/problem/9038

import java.io.*;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());
        for(int t=0; t<T; ++t){
            int w = Integer.parseInt(br.readLine());
            String[] input = br.readLine().split(" ");
            int cnt = 0;
            int len = 0;
            for(String word : input){
                int wordLen = word.length();
                if (len + wordLen > w) {
                    cnt++;
                    len = wordLen;
                }
                else
                    len += wordLen;

                if (len < w)
                    len++;
            }
            if(len != 0)
                cnt++;
            sb.append(cnt).append('\n');
        }

        System.out.print(sb);
    }
}
