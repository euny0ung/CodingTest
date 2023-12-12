import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int N, K;
	static int[] V;
	static int[] W;
	static int[][] dp;

	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine());
		N=Integer.parseInt(st.nextToken());
		K=Integer.parseInt(st.nextToken());
		
		V=new int[101];
		W=new int[101];
		
		dp=new int[101][100001];
		
		for(int i=1; i<=N; i++) {
			st=new StringTokenizer(br.readLine());
			
			W[i]=Integer.parseInt(st.nextToken());
			V[i]=Integer.parseInt(st.nextToken());
		}
		
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=K; j++) {
				if(j>=W[i])	dp[i][j]=Math.max(dp[i-1][j], dp[i-1][j-W[i]]+V[i]);
				else dp[i][j]=dp[i-1][j];
			}
			
		}
		
		System.out.println(dp[N][K]);
		

	}

}