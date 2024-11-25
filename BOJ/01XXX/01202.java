//https://www.acmicpc.net/problem/1202

import java.io.*;
import java.util.*;

class Jewel implements Comparable<Jewel>{
    int value, weight;
    public Jewel(int value, int weight){
        this.value = value;
        this.weight = weight;
    }

    @Override
    public int compareTo(Jewel j){
        if(j.weight == this.weight)
            return j.value - this.value;
        return this.weight - j.weight;
    }
}

public class Main{
    public static int n, k;
    public static long ans;
    public static int[] bags;
    public static Jewel[] jewels;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        jewels = new Jewel[n];
        bags = new int[k];
        for(int i=0; i<n; ++i){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            jewels[i] = new Jewel(b, a);
        }

        for(int i=0; i<k; ++i)
            bags[i] = Integer.parseInt(br.readLine());

        Arrays.sort(bags);
        Arrays.sort(jewels);

        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        for(int i=0, j=0; i<k; ++i){
            while(j<n){
                if(bags[i] < jewels[j].weight)
                    break;
                pq.add(jewels[j++].value);
            }

            if(!pq.isEmpty())
                ans += pq.poll();
        }
        System.out.print(ans);
    }
}
