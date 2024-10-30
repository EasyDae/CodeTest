//https://www.acmicpc.net/problem/9772

import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringBuilder sb = new StringBuilder();
        while(true){
            StringTokenizer st = new StringTokenizer(br.readLine());
            double a = Double.parseDouble(st.nextToken());
            double b = Double.parseDouble(st.nextToken());

            if(a==0 && b==0) {
                sb.append("AXIS\n");
                System.out.print(sb);
                return;
            }

            if(a==0 || b==0)
                sb.append("AXIS\n");
            else{
                if(a>0 && b>0)
                    sb.append("Q1\n");
                if(a>0 && b<0)
                    sb.append("Q4\n");
                if(a<0 && b>0)
                    sb.append("Q2\n");
                if(a<0 && b<0)
                    sb.append("Q3\n");
            }
        }
    }
}
