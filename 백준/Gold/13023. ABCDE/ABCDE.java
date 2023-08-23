import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

/*
 * 1. 모든 노드에서 깊이 우선탐색
 * 2. 한번 dfs를 돌때마다 cnt++
 * 3. 만약 cnt가 5가 되면 1을 출력하고 dfs를 벗어남
 * 4. 모든 노드에서 탐색을 했는데 5가 안되면 0 출력
 */

public class Main {
	
	static int N,M;
	static int cnt;
	static int result;
	static List<Integer>[] list;
	static boolean[] visited;
	
	public static void main(String[] args) throws IOException {
		
		//a,b는 최대 1999		
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine());
		
		N=Integer.parseInt(st.nextToken());
		M=Integer.parseInt(st.nextToken());
		
		list=new ArrayList[N+1];
		
		
		for(int i=0; i<N+1; i++) {
			list[i]=new ArrayList<Integer>();
		}
		
		for(int i=0; i<M; i++) {
			st=new StringTokenizer(br.readLine());
			int a=Integer.parseInt(st.nextToken());
			int b=Integer.parseInt(st.nextToken());
			list[a].add(b);
			list[b].add(a);
		}
		
		for(int i=0; i<N; i++) {
			cnt=0;
			result=0;
			visited=new boolean[N+1];
			DFS(i, cnt);
			if(result==1) break;
		}
		
		System.out.println(result);
	}
	
	static void DFS(int node, int depth) {
		
		visited[node]=true;
		int sz=list[node].size();
		
		if(depth==4) {
			result=1;
			return;
		}
		
		for(int i=0; i<sz; i++) {
			int linkedNode=list[node].get(i);
			if(!visited[linkedNode]) {
				DFS(linkedNode, depth+1);
				visited[linkedNode]=false;
			}
		}
	}
}