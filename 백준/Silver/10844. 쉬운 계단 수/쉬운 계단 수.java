import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	static int N;
	static int[][] dp;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		N=Integer.parseInt(br.readLine());
		dp=new int[N+1][11];
		
		int mod=1_000_000_000;
		
		// 길이가 1이고 마지막 숫자가 i인 경우는 한가지뿐이다
		for(int i=1; i<=9; i++) {
			dp[1][i]=1;
		}
		
		for(int i=2; i<=N; i++) {
			for(int j=0; j<=9; j++) {
				if(j==0) {
					dp[i][j]=dp[i-1][j+1];
				}
				else if(j==9) {
					dp[i][j]=dp[i-1][j-1];
				}
				else {
					dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
				}
				
				dp[i][j]%=mod;
			}
			
		}
		
		int ans=0;
		
		for(int i=0; i<=9; i++) {
			ans=(ans+dp[N][i])%mod;
		}
		
		System.out.println(ans);
		
	}

}