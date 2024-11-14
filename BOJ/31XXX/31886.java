//https://www.acmicpc.net/problem/31866

import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        char ch;
        switch(a){
            case 0:
                if(b==5) ch = '<';
                else if(b==0) ch = '=';
                else ch = '>';
                break;
            case 2:
                if(b==0) ch = '<';
                else if(b==2) ch = '=';
                else ch = '>';
                break;
            case 5:
                if(b==2) ch = '<';
                else if(b==5) ch = '=';
                else ch = '>';
                break;
            default:
                if(b==0 || b==2 || b==5) ch = '<';
                else ch = '=';
        }
        System.out.print(ch);
    }
}
