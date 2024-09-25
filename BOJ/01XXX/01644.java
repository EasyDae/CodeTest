//https://www.acmicpc.net/problem/1644

import java.io.*;
import java.util.*;

public class Main{
    public static boolean[] prime;
    public static List<Integer> list;
    public static int n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        prime = new boolean[n+1];
        Prime();

        int left = 0, right = 0, sum = 0, ans = 0;
        while(true){
            if(sum >= n)
                sum -= list.get(left++);
            else if(right == list.size())
                break;
            else
                sum += list.get(right++);

            if(sum == n)
                ans++;
        }

        System.out.println(ans);
    }

    public static void Prime(){
        for(int i=2; i<=n; ++i){
            if(!prime[i])
                for(int j=2*i; j<=n; j+=i)
                    prime[j] = true;
        }

        list = new ArrayList<>();
        for(int i=2; i<=n; ++i)
            if(!prime[i])
                list.add(i);
    }
}
