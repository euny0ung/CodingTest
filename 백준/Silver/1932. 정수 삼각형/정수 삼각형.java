import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

// 풀다 말았음
public class Main {
	
	static int N;
	static int[][] dp;
	static int result;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		N=Integer.parseInt(br.readLine());
		dp=new int[N][N];
		int max=Integer.MIN_VALUE;
		
		for(int i=0; i<N; i++) {
			StringTokenizer st=new StringTokenizer(br.readLine());
			for(int j=0; j<=i; j++) {
				dp[i][j]=Integer.parseInt(st.nextToken());
			}
		}
		
		
		for(int i=1; i<N; i++) {
			for(int j=0; j<=i; j++) {
				if(j==0) {
					dp[i][0]=dp[i][0]+dp[i-1][0];
				}
				else if(i==j) {
					dp[i][j]=dp[i-1][j-1]+dp[i][j];
				}
				else {
					dp[i][j]=Math.max(dp[i-1][j-1], dp[i-1][j])+dp[i][j];
				}
			}
		}
		
		for(int i=0; i<N; i++) {
			max=Math.max(dp[N-1][i], max);
		}
		
		System.out.println(max);
	
	}
}