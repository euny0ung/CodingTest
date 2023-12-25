import java.io.BufferedReader;

import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int T, N;
	static int[][] dp;
	static int[][] arr;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb=new StringBuilder();
		T=Integer.parseInt(br.readLine());
		
		for(int i=0; i<T; i++) {
			N=Integer.parseInt(br.readLine());
			
			dp=new int[2][N+1];
			arr=new int[2][N+1];
			
			for(int j=0; j<2; j++) {
				StringTokenizer st=new StringTokenizer(br.readLine());
				for(int k=1; k<=N; k++) {
					arr[j][k]=Integer.parseInt(st.nextToken());
				}
			}
			
			dp[0][0]=dp[1][0]=0;
			
			dp[0][1]=arr[0][1];
			dp[1][1]=arr[1][1];
			
			for(int j=2; j<=N; j++) {
				dp[0][j]=Math.max(dp[1][j-1], dp[1][j-2])+arr[0][j];
				dp[1][j]=Math.max(dp[0][j-1], dp[0][j-2])+arr[1][j];
			}
			
			int max=Math.max(dp[0][N], dp[1][N]);
			
			sb.append(max).append("\n");
			
		}
		System.out.println(sb);
		
	}
}