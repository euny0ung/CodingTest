import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int N;
	static int[] arr;
	static int[] dp;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		N=Integer.parseInt(br.readLine());
		
		arr=new int[N];
		dp=new int[N];
		
		StringTokenizer st=new StringTokenizer(br.readLine());
		
		
		
		for(int i=0; i<N; i++) {
			
			arr[i]=Integer.parseInt(st.nextToken());
		}
		
		dp[0]=arr[0];
		
		int maxValue=arr[0];
		
		for(int i=1; i<N; i++) {
			dp[i]=Math.max(dp[i-1]+arr[i], arr[i]);
			
			if(maxValue<dp[i]) maxValue=dp[i];
		}
		
		
		System.out.println(maxValue);
		
	}

}