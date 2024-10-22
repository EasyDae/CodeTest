//https://www.acmicpc.net/problem/1092

import java.io.*;
import java.util.*;

public class Main {
    public static int n, m;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        List<Integer> crane = new ArrayList<>();
        StringTokenizer st = new StringTokenizer(br.readLine());

        for(int i=0; i<n; ++i)
            crane.add(Integer.parseInt(st.nextToken()));

        m = Integer.parseInt(br.readLine());
        List<Integer> box = new ArrayList<>();
        st = new StringTokenizer(br.readLine());

        for(int i=0; i<m; ++i)
            box.add(Integer.parseInt(st.nextToken()));

        crane.sort(Collections.reverseOrder());
        box.sort(Collections.reverseOrder());

        if(crane.get(0) < box.get(0)){
            System.out.print(-1);
            return;
        }

        int ans = 0;
        while(!box.isEmpty()){
            int boxidx = 0, craneidx = 0;

            while(craneidx < n){
                if(boxidx == box.size())
                    break;
                else if(crane.get(craneidx) >= box.get(boxidx)){
                    box.remove(boxidx);
                    craneidx++;
                }
                else
                    boxidx++;
            }
            ans++;
        }

        System.out.print(ans);
    }
}
