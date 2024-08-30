//https://www.acmicpc.net/problem/1068

import java.io.*;
import java.util.*;

public class Main {
	static List<Integer>[] graph;
	static boolean visited[];
	static int d;
	static int cnt;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		graph = new ArrayList[n];
		for(int i=0; i<n; ++i)
			graph[i] = new ArrayList<>();
		
		visited = new boolean[n+1];
		st = new StringTokenizer(br.readLine());
		int root = -1;
		
		for(int i=0; i<n; ++i) {
			int tmp = Integer.parseInt(st.nextToken());
			if(tmp == -1)
				root = i;
			else {
				graph[i].add(tmp);
				graph[tmp].add(i);
			}
		}
		
		d = Integer.parseInt(br.readLine());
		if(d == root)
			System.out.println(0);
		else {
			DFS(root);
			System.out.println(cnt);
		}
	}
	
	public static void DFS(int n) {
		visited[n] = true;
		
		int node = 0;
		for(var x : graph[n]) {
			if(x != d && !visited[x]) {
				node++;
				DFS(x);
			}
		}
		
		if(node == 0)
			cnt++;
	}
}
