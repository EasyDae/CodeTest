//https://devtech-ocean.tistory.com/14

import java.io.*;
import java.util.*;

public class Main{
    public static int n, m, x, y, k;
    public static int[] dice = new int[7];
    public static int[][] arr;
    public static int[] dx = {0,0,-1,1};
    public static int[] dy = {1,-1,0,0};
    public static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());
        y = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        arr = new int[n][m];
        for(int i=0; i<n; ++i){
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<m; ++j)
                arr[i][j] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        for(int i=0; i<k; ++i)
            roll(Integer.parseInt(st.nextToken()));

        System.out.println(sb);
    }

    public static void roll(int num){
        int ax = x + dx[num-1];
        int ay = y + dy[num-1];

        if(ax < 0 || ax >= n || ay < 0 || ay >= m)
            return;

        int tmp = dice[6];
        switch(num){
            case 1:
                dice[6] = dice[3];
                dice[3] = dice[1];
                dice[1] = dice[4];
                dice[4] = tmp;
                break;
            case 2:
                dice[6] = dice[4];
                dice[4] = dice[1];
                dice[1] = dice[3];
                dice[3] = tmp;
                break;
            case 3:
                dice[6] = dice[5];
                dice[5] = dice[1];
                dice[1] = dice[2];
                dice[2] = tmp;
                break;
            case 4:
                dice[6] = dice[2];
                dice[2] = dice[1];
                dice[1] = dice[5];
                dice[5] = tmp;
        }

        x = ax; y = ay;

        if(arr[x][y] == 0)
            arr[x][y] = dice[6];
        else{
            dice[6] = arr[x][y];
            arr[x][y] = 0;
        }

        sb.append(dice[1]).append("\n");
    }
}
