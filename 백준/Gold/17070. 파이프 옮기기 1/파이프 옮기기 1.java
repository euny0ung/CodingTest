import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		int N=0;
		int result=0;
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		N=Integer.parseInt(br.readLine());
		
		int[][][] dp=new int[N][N][3];
		int[][] arr=new int[N][N];
		
		dp[0][1][0]=1;
		
		
		for(int i=0; i<N; i++) {
			StringTokenizer st=new StringTokenizer(br.readLine());
			for(int j=0; j<N; j++) {
				arr[i][j]=Integer.parseInt(st.nextToken());
			}
		}
		
		for(int i=0; i<N; i++) {
			for(int j=2; j<N; j++) {
				
				// 벽인 경우 파이프를 설치하지 않는다
				if(arr[i][j]==1) continue;
				dp[i][j][0]=dp[i][j-1][0]+ dp[i][j-1][2];
				
				// 첫 행의 가로의 경우 가로로만 설치가 가능함
				if(i==0) continue;
				dp[i][j][1]=dp[i-1][j][1]+ dp[i-1][j][2];
				
				// 현재 칸의 윗칸, 왼쪽 칸에 벽이 없어야함
				if(arr[i][j-1] == 1 || arr[i-1][j]==1) continue;
				dp[i][j][2]=dp[i-1][j-1][0]+dp[i-1][j-1][1]+ dp[i-1][j-1][2];
			}
		}
		
		for(int i=0; i<3; i++) {
			result+=dp[N-1][N-1][i];
		}
		
		System.out.println(result);
		
		
	}
}