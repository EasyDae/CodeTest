//https://www.acmicpc.net/problem/30889

import java.io.*;
import java.util.*;
import java.util.stream.IntStream;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        char[][] arr = new char[10][20];

        IntStream.range(0, 10).forEach(i -> Arrays.fill(arr[i], '.'));

        for(int i=0; i<n; ++i){
            String seat = br.readLine();
            int low = seat.charAt(0)-'A';
            int col = seat.length() == 3 ? 10 * (seat.charAt(1)-'0') + seat.charAt(2)-'0' : seat.charAt(1)-'0';
            arr[low][col-1] = 'o';
        }

        for(int i=0; i<10; ++i){
            for(int j=0; j<20; ++j)
                bw.write(arr[i][j]);
            bw.write('\n');
        }
        bw.flush();
    }
}
