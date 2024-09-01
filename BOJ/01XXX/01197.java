//https://www.acmicpc.net/problem/1197

import java.io.*;
import java.util.*;

class Node implements Comparable<Node>{
	int to;
	int from;
	int val;
	
	public Node(int to, int from, int val) {
		this.to = to;
		this.from = from;
		this.val = val;
	}
	
	@Override
	public int compareTo(Node N) {
		return this.val - N.val;
	}
}

public class Main {
	public static int n;
	public static int[] parent;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int v = Integer.parseInt(st.nextToken());
		int e = Integer.parseInt(st.nextToken());
		Queue<Node> pq = new PriorityQueue<Node>();
		parent = new int[v + 1];
		for(int i=1; i<=v; ++i)
			parent[i] = i;
		
		for(int i=0; i<e; ++i) {
			st = new StringTokenizer(br.readLine());
			pq.add(new Node(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
		}
		
		int size = pq.size();
		int total = 0;
		for(int i=0; i<size; ++i) {
			Node tmp = pq.poll();
			int x = find(tmp.to);
			int y = find(tmp.from);
			
			if(!isSameParent(x, y)) {
				total += tmp.val;
				union(tmp.to, tmp.from);
			}
		}
		
		System.out.println(total);
	}
	
	public static int find(int a) {
		if(parent[a] == a)
			return a;
		
		return parent[a] = find(parent[a]);
	}
	
	public static void union(int a, int b) {
		a = find(a);
		b = find(b);
		
		if(a != b)
			parent[b] = a;
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
