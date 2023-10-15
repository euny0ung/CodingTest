import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		int N=0;
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		N=Integer.parseInt(br.readLine());
		
		long[][] dp=new long[N][3];
		
		for(int i=0; i<3; i++) {
			dp[0][i]=1;
		}
		
		for(int i=1; i<N; i++) {
			dp[i][0]=(dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%9901;
			dp[i][1]=(dp[i-1][0]+dp[i-1][2])%9901;
			dp[i][2]=(dp[i-1][0]+dp[i-1][1])%9901;
		}
		
		long result=(dp[N-1][0]+dp[N-1][1]+dp[N-1][2])%9901;
		
		System.out.println(result);

	}

}