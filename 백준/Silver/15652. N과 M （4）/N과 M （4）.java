import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	
	static int N, M;
	static int[] arr;
	static boolean[] visited;

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine());
		
		N=Integer.parseInt(st.nextToken());
		M=Integer.parseInt(st.nextToken());
		arr=new int[9];
		visited=new boolean[9];
		
		permutation(1, 0);
		
	}

	private static void permutation(int num, int cnt) {
		
		// 
		if(cnt==M) {
			
			for(int i=0; i<M; i++) {
				System.out.print(arr[i]+" ");
			}
			System.out.println();
		}
		else {
			for(int i=num; i<=N; i++) {
				visited[i]=true;
				arr[cnt]=i;
				permutation(i, cnt+1);
				visited[i]=false;
			}
		}
		
	}

}