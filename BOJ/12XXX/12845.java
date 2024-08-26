//https://www.acmicpc.net/problem/12845

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
	    int n = Integer.parseInt(st.nextToken());
	    int Max = 0, idx = 0;
	    List<Integer> arr = new ArrayList<>();
	    st = new StringTokenizer(br.readLine());
	    
	    if(n==1) {
	    	System.out.println(st.nextToken());
	    	return;
	    }
	    
	    for(int i=0; i<n; ++i) {
	    	int l = Integer.parseInt(st.nextToken());
	    	arr.add(l);
	    	if(Max < l) {
	    		Max = l;
	    		idx = i;
	    	}
	    }
	    
	    int ans = 0;
	    while(arr.size() - 1 != idx) {
	    	ans += Max + arr.get(idx + 1);
	    	arr.remove(idx + 1);
	    }
	    
	    while(arr.size() != 1) {
	    	ans += Max + arr.get(arr.size() - 2);
	    	arr.remove(arr.size() - 2);
	    }
	    
	    System.out.println(ans);
	}
}
