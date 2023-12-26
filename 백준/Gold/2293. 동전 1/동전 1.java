import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N,K;
	static int[]dp;
	static int[] coin;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine());
		
		N=Integer.parseInt(st.nextToken());
		K=Integer.parseInt(st.nextToken());
		
		coin=new int[N+1];
		dp=new int[K+1];
		
		
		// 0원을 만드는 경우의 수 = 아무 동전도 안씀 = 1가지
		dp[0]=1;
		
		for(int i=1; i<=N; i++) {
			coin[i]=Integer.parseInt(br.readLine());
		}

		for(int i=1; i<=N; i++) {
			for(int j=coin[i]; j<=K; j++) {
				dp[j]+=dp[j-coin[i]];
			}
		}
		
		System.out.println(dp[K]);
		
	}

}