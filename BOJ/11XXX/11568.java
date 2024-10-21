//https://www.acmicpc.net/problem/11568

import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        List<Integer> list = new ArrayList<>();
        StringTokenizer st = new StringTokenizer(br.readLine());

        list.add(Integer.parseInt(st.nextToken()));
        for(int i=1; i<n; ++i){
            int num = Integer.parseInt(st.nextToken());

            for(int j=0; j<list.size(); ++j){
                if(list.get(j) >= num){
                    list.remove(j);
                    list.add(j, num);
                    break;
                }

                if(j==list.size()-1)
                    list.add(num);
            }
        }

        System.out.println(list.size());
    }
}
