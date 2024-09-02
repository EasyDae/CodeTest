//https://www.acmicpc.net/problem/1922

import java.io.*;
import java.util.*;

class Node implements Comparable<Node>{
	int to;
	int from;
	int cost;
	
	public Node(int to, int from, int cost) {
		this.to = to;
		this.from = from;
		this.cost = cost;
	}
	
	@Override
	public int compareTo(Node N) {
		return this.cost - N.cost;
	}
}

public class Main {
	public static int n;
	public static int[] parent;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		int m = Integer.parseInt(br.readLine());
		parent = new int[n + 1];
		Queue<Node> pq = new PriorityQueue<>();
		
		for(int i=1; i<=n; ++i)
			parent[i] = i;
		
		for(int i=0; i<m; ++i) {
			st = new StringTokenizer(br.readLine());
			pq.add(new Node(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
		}
		
		int total = 0;
		int len = pq.size();
		
		for(int i=0; i<len; ++i) {
			Node tmp = pq.poll();
			int x = find(tmp.to);
			int y = find(tmp.from);
			if(!isSameParent(x, y)) {
				total += tmp.cost;
				union(x, y);
			}
		}
		
		System.out.println(total);
	}
	
	public static int find(int n) {
		if(parent[n] == n)
			return n;
		
		return parent[n] = find(parent[n]);
	}
	
	public static void union(int a, int b) {
		int x = find(a);
		int y = find(b);
		
		if(x != y)
			parent[x] = parent[y];
	}
	
	public static boolean isSameParent(int x, int y ) {
		x = find(x);
		y = find(y);
		if(x==y) 
			return true;
		else 
			return false;
	}
}
