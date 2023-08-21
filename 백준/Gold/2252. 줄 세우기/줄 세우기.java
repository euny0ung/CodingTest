import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static int N,M;
	static int a,b;
	static int []degrees;
	static List<Integer>[] list;
	static Queue<Integer> q=new ArrayDeque<>();
	static StringBuilder sb=new StringBuilder();
	
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine());
		
		
		
		N=Integer.parseInt(st.nextToken());
		M=Integer.parseInt(st.nextToken());
		
		degrees=new int[N+1];
		list=new ArrayList[N+1];
		
		for(int i=1; i<N+1; i++) {
			list[i]=new ArrayList<>();
		}
		
		for(int i=0; i<M; i++) {
			st=new StringTokenizer(br.readLine());
			a=Integer.parseInt(st.nextToken());
			b=Integer.parseInt(st.nextToken());
			list[a].add(b);
			degrees[b]++;
		}
		
		BFS();
		
		System.out.println(sb);
		
	}
	
	static void BFS() {
		// 진입 차수가 0인 과목 모두 큐에 넣기
		for(int i=1; i<=N; i++) {
			if(degrees[i]==0) {
				q.add(i);
			}
		}
		
		while(!q.isEmpty()) {
			int node=q.poll();
			sb.append(node+" ");
			
			for(int adj : list[node]) {
				--degrees[adj];
				if(degrees[adj]==0) {
					q.add(adj);
				}
				
				
			}
		}
		
		
		
		
	}
}