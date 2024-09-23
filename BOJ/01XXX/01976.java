//https://www.acmicpc.net/problem/1976

import java.io.*;
import java.util.*;

public class Main{
    public static int[] parent;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());
        parent = new int[n+1];
        for(int i=1; i<=n; ++i)
            parent[i] = i;

        for(int i=1; i<=n; ++i){
            st = new StringTokenizer(br.readLine());
            for(int j=1; j<=n; ++j){
                int tmp = Integer.parseInt(st.nextToken());
                if(tmp == 1)
                    union(i, j);
            }
        }

        st = new StringTokenizer(br.readLine());
        int start = find(Integer.parseInt(st.nextToken()));
        for(int i=1; i<m; ++i){
            int cur = Integer.parseInt(st.nextToken());
            if(start != find(cur)) {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }

    public static int find(int x){
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    public static void union(int x, int y){
        x = find(x);
        y = find(y);

        parent[y] = x;
    }
}
