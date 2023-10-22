import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 배열 크기를 N으로 잡으면 N이 1,2일때 에러 발생.. 경우를 따로 분리하는 것보다 그냥 배열 크기를 301로 고정하는게 낫다고 판단했음

public class Main {

	static int N;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		N=Integer.parseInt(br.readLine());
		int[] dp=new int[301];
		int[] arr=new int[301];
		
		for(int i=0; i<N; i++) {
			arr[i]=Integer.parseInt(br.readLine());
		}
		
		dp[0]=arr[0];
		dp[1]=arr[0]+arr[1];
		dp[2]=Math.max(arr[0]+arr[2], arr[1]+arr[2]);
		
		for(int i=3; i<N; i++) {
			dp[i]=Math.max(dp[i-3]+arr[i-1]+arr[i], dp[i-2]+arr[i]);
		}
		
		System.out.println(dp[N-1]);
	}
	

}