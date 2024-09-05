//https://www.acmicpc.net/problem/4386

import java.io.*;
import java.util.*;

class Point{
	int idx;
	double x;
	double y;
	
	public Point(int idx, double x, double y) {
		this.idx = idx;
		this.x = x;
		this.y = y;
	}
}

class Node implements Comparable<Node>{
	int from;
	int to;
	double cost;
	
	public Node(int from, int to, double cost) {
		this.from = from;
		this.to = to;
		this.cost = cost;
	}
	
	@Override
	public int compareTo(Node n) {
		if(this.cost < n.cost)
			return -1;
		return 1;
	}
}

public class Main {
	public static int[] parent;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		parent = new int[n];
		for(int i=0; i<n; ++i)
			parent[i] = i;
		
		Point[] points = new Point[n];
		for(int i=0; i<n; ++i) {
			st = new StringTokenizer(br.readLine());
			
			points[i] = new Point(i, Double.parseDouble(st.nextToken()), Double.parseDouble(st.nextToken()));
		}
		
		Queue<Node> pq = new PriorityQueue<>();
		
		for(int i=0; i<n; ++i)
			for(int j=i+1; j<n; ++j)
				pq.add(new Node(points[i].idx, points[j].idx, dist(points[i], points[j])));
		
		double total = 0;
		while(!pq.isEmpty()) {
			Node tmp = pq.poll();
			int a = tmp.from;
			int b = tmp.to;
			
			if(find(a) != find(b)) {
				union(a, b);
				total += tmp.cost;
			}
		}
		
		System.out.printf("%.2f", total);
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
	
	public static double dist(Point p1, Point p2) {
		return Math.sqrt(Math.pow(p1.x - p2.x, 2) + Math.pow(p1.y - p2.y, 2));
	}
}
