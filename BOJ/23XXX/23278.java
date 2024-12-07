//https://www.acmicpc.net/problem/23278

import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken()), l = Integer.parseInt(st.nextToken()), h = Integer.parseInt(st.nextToken());
        double[] arr = new double[n];
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; ++i)
            arr[i] = Double.parseDouble(st.nextToken());

        Arrays.sort(arr);
        double sum = 0;
        for(int i=l; i<n-h; ++i)
            sum += arr[i];
        System.out.print(sum/(n-(l+h)));
    }
}
