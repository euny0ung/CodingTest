import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
 // 중복 순열
	static int N, M;
	static int[] arr;
	static int[] result;
	static boolean[] visited;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st= new StringTokenizer(br.readLine());
		
		N=Integer.parseInt(st.nextToken());
		M=Integer.parseInt(st.nextToken());
		
		arr=new int[N];
		result=new int[M];
		visited=new boolean[N];
		
		
		st=new StringTokenizer(br.readLine());
		
		for(int i=0; i<N; i++) {
			arr[i]=Integer.parseInt(st.nextToken());
		}
	
		Arrays.sort(arr);
		
		perm(0, 0);
	}

	private static void perm(int cnt, int idx) {
		// TODO Auto-generated method stub
		if(cnt==M) {
			for(int i=0; i<M; i++) {
				System.out.print(result[i]+" ");
			}
			System.out.println();
			return;
		}
		for(int i=0; i<N; i++) {
			if(!visited[i]) {
				visited[i]=true;
				result[idx]=arr[i];
				perm(cnt+1, idx+1);
				visited[i]=false;
			}
			
		}
		
	}
	
	
}