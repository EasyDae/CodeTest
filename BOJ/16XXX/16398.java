//https://www.acmicpc.net/problem/16398

import java.io.*;
import java.util.*;

class Node implements Comparable<Node>{
	int from;
	int to;
	int cost;
	
	public Node(int from, int to, int cost) {
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
	static int parent[];
	static int n;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int n = Integer.parseInt(br.readLine());
		parent = new int[n+1];
		for(int i=1; i<=n; ++i)
			parent[i] = i;
		
		Queue<Node> pq = new PriorityQueue<>();
		
		for(int i=1; i<=n; ++i) {
			st = new StringTokenizer(br.readLine());
			
			for(int j=1; j<=n; ++j) {
				int dist = Integer.parseInt(st.nextToken());
				
				if(dist != 0)
					pq.add(new Node(i, j, dist));
			}
		}
		
		int total = 0;
		while(!pq.isEmpty()) {
			Node tmp = pq.poll();
			int x = find(tmp.from);
			int y = find(tmp.to);
			
			if(x != y) {
				total += tmp.cost;
				union(x, y);
			}
		}
		
		System.out.println(total);
	}
	
	public static int find(int x) {
		if(parent[x] == x)
			return x;
		
		return parent[x] = find(parent[x]);
	}
	
	public static void union(int a, int b) {
		a = find(a);
		b = find(b);
		
		parent[b] = a;
	}
}
