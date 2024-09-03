//https://www.acmicpc.net/problem/1647

import java.io.*;
import java.util.*;

class Node implements Comparable<Node>{
	int from;
	int to;
	int cost;
	
	public Node(int to, int from, int cost) {
		this.from = from;
		this.to = to;
		this.cost = cost;
	}
	
	@Override
	public int compareTo(Node n) {
		return this.cost - n.cost;
	}
}

public class Main {
	public static int n, m;
	public static int[] parent;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		parent = new int[n + 1];
		Queue<Node> pq = new PriorityQueue<>();
		
		for(int i=1; i<=n; ++i)
			parent[i] = i;
		
		for(int i=0; i<m; ++i) {
			st = new StringTokenizer(br.readLine());
			
			pq.add(new Node(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
		}
		
		int total = 0;
		int big = 0;
		while(!pq.isEmpty()) {
			Node tmp = pq.poll();
			int a = find(tmp.from);
			int b = find(tmp.to);
			
			if(find(a) != find(b)) {
				total += tmp.cost;
				union(a, b);
				
				big = tmp.cost;
			}
		}
		
		System.out.println(total - big);
	}
	
	public static int find(int x) {
		if(parent[x] == x)
			return x;
		
		return parent[x] = find(parent[x]);
	}
	
	public static void union(int a, int b) {
		a = find(a);
		b = find(b);
		
		if(a != b)
			parent[b] = a;
	}
}
