import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	static int N, input;
	static int[] dp;
	static int[] arr;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		N=Integer.parseInt(br.readLine());
		
		dp=new int[N+1];
		arr=new int[N+1];
		
		for(int i=1; i<=N; i++) {
			arr[i]=Integer.parseInt(br.readLine());
		}
		
		if(N==1) System.out.println(arr[1]);
		else if(N==2) System.out.println(arr[1]+arr[2]);
		else {
			dp[0]=0;
			dp[1]=arr[1];
			dp[2]=arr[1]+arr[2];
			
			
			// i번째(현재 잔)을 선택하지 않아야 더 큰 경우도 있음!!
			for(int i=3; i<=N; i++) {
				dp[i]=Math.max(dp[i-2]+arr[i], Math.max(dp[i-3]+arr[i-1]+arr[i], dp[i-1]));

			}

			System.out.println(dp[N]);	
		}
		
	}

}