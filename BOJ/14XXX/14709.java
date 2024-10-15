//https://www.acmicpc.net/problem/14709

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        if(n != 3){
            System.out.print("Woof-meow-tweet-squeek");
            return;
        }
        int[][] arr = new int[6][6];
        for(int i=0; i<3; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            arr[a][b] = arr[b][a] = 1;
        }

        if(arr[1][3] == 1 && arr[1][4] == 1 && arr[3][4] == 1)
            System.out.print("Wa-pa-pa-pa-pa-pa-pow!");
        else
            System.out.print("Woof-meow-tweet-squeek");
    }
}
