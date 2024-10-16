//https://www.acmicpc.net/problem/4396

import java.io.*;
import java.util.*;

public class Main {
    public static char[][] map, open;
    public static int[] dx = {1,0,-1,1,-1,1,0,-1};
    public static int[] dy = {1,1,1,0,0,-1,-1,-1};
    public static int n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        map = new char[n][n];
        open = new char[n][n];

        for(int i=0; i<n; ++i)
            map[i] = br.readLine().toCharArray();
        for(int i=0; i<n; ++i)
            open[i] = br.readLine().toCharArray();

        boolean flag = false;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(open[i][j] == 'x'){
                    if(map[i][j] == '*'){
                        flag = true;
                        continue;
                    }

                    int cnt = 0;
                    for(int k=0; k<8; ++k){
                        int x = i + dx[k];
                        int y = j + dy[k];

                        if(x < 0 || x >= n || y < 0 || y >= n || map[x][y] != '*')
                            continue;

                        cnt++;
                    }

                    open[i][j] = (char)(cnt+'0');
                }
            }
        }

        if(flag){
            for(int i=0; i<n; ++i)
                for (int j = 0; j < n; ++j)
                    if(map[i][j] == '*')
                        open[i][j] = '*';
        }

        StringBuilder sb = new StringBuilder();
        for(int i=0; i<n; ++i) {
            for (int j = 0; j < n; ++j) {
                sb.append(open[i][j]);
            }
            sb.append('\n');
        }

        System.out.println(sb);
    }
}
