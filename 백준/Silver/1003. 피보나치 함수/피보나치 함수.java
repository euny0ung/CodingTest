import java.util.Scanner;

public class Main {
	
	static int zeroCall;
	static int oneCall;
	
	static class Dp{
		int zero;
		int one;
		Dp(int zero, int one){
			this.zero=zero;
			this.one=one;
		}
	}
	
	
	
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		StringBuilder sb=new StringBuilder();
		
		int T=0, N=0;
		T=sc.nextInt();
		
		Dp[] dp=new Dp[41];
		
		for(int i=0; i<dp.length; i++) {
			dp[i]=new Dp(0, 0);
		}
		
		dp[0]=new Dp(1,0);
		dp[1]=new Dp(0,1);

		
		for(int i=2; i<=40; i++) {
			dp[i].zero=dp[i-1].zero+dp[i-2].zero;
			dp[i].one=dp[i-1].one+dp[i-2].one;
//			System.out.println(i+"번째 "+dp[i].zero+" "+dp[i].one);
		}
		
		for(int i=0; i<T; i++) {
			N=sc.nextInt();
			
			sb.append(dp[N].zero).append(" ").append(dp[N].one).append("\n");
		}
		
		System.out.println(sb);
	}
}