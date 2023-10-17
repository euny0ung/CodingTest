import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;


public class Main {
	
	static int t, n;
	static List<int[]> home;
	static List<int[]> store;
	static List<int[]> destination;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb=new StringBuilder();
		StringTokenizer st;
		t=Integer.parseInt(br.readLine());
		
		for(int tc=0; tc<t; tc++) {

			home=new ArrayList<>();
			store=new ArrayList<>();
			destination=new ArrayList<>();
			
			n=Integer.parseInt(br.readLine()); // 편의점 개수
			st=new StringTokenizer(br.readLine());
			
			home.add(new int[] {Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())});
			
			for(int i=0; i<n; i++) {
				st=new StringTokenizer(br.readLine());
				store.add(new int[] {Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())});
			}
			
			st=new StringTokenizer(br.readLine());
			destination.add(new int[] {Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())});			
		
			
			if(move(home.get(0)[0], home.get(0)[1], n)) {
				sb.append("happy").append("\n");
			}
			else {
				sb.append("sad").append("\n");
			}
			
			
		}
		System.out.println(sb);
	}

	private static boolean move(int a, int b, int num) {
		
		Queue<int[]>q=new ArrayDeque<>();
		boolean[] visited=new boolean[num];
		
		q.add(new int[] {a,b});
		
		while(!q.isEmpty()) {
			int[] qArr=q.poll();
			int x=qArr[0];
			int y=qArr[1];
			
			// 목적지에 도착한 경우
			if(Math.abs(x-destination.get(0)[0])+Math.abs(y-destination.get(0)[1])<=1000) return true;
			
			// 편의점
			for(int i=0; i<n; i++) {
				int storeX=store.get(i)[0];
				int storeY=store.get(i)[1];
				if(Math.abs(x-storeX)+Math.abs(y-storeY)<=1000 && !visited[i]) { 
					visited[i]=true;
					q.add(new int[] {storeX, storeY});
				}
					
					
			}
		}
		
		return false;
		
		
		
	}
}