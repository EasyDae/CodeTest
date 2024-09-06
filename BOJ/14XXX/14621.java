//https://www.acmicpc.net/problem/14621

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
	public static int[] parent;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		parent = new int[n + 1];
		for(int i=1; i<=n; ++i)
			parent[i] = i;
		
		char[] univ = new char[n+1];
		st = new StringTokenizer(br.readLine());
		for(int i=1; i<=n; ++i)
			univ[i] = st.nextToken().charAt(0);
		
		Queue<Node> pq = new PriorityQueue<>();
		for(int i=0; i<m; ++i) {
			st = new StringTokenizer(br.readLine());
			
			pq.add(new Node(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
		}
		
		int cnt = 0;
		int total = 0;
		while(!pq.isEmpty()) {
			Node tmp = pq.poll();
			int a = tmp.from;
			int b = tmp.to;
			
			if(find(a) != find(b)) {
				if(univ[a] != univ[b]) {
					cnt++;
					total += tmp.cost;
					union(a, b);
				}
			}
		}
		
		if(cnt != n-1)
			System.out.println(-1);
		else
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
