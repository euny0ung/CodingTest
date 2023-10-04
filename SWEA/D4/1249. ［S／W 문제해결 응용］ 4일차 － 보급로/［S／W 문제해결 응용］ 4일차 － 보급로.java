import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

/*1. 4방 탐색하면서 dp값 구하기
2. 해당 좌표를 큐에 넣기
3. 큐가 빌때까지 계속
4. 그러니까 약간 DP + BFS 느낌... 인듯
*/

public class Solution {
	
	static int testCase;
	static int[] dx= {0,1,-1,0}; // 우 하 상 좌
	static int[] dy= {1,0,0,-1};
	static int N=0;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb=new StringBuilder();
		
		testCase=Integer.parseInt(br.readLine());
		
		for(int tc=1; tc<=testCase; tc++) {
			
			N=Integer.parseInt(br.readLine());
			
			int[][] map=new int[N][N];
			int[][] dp=new int[N][N];
			Queue<int[]>q=new LinkedList<>();
			
			
			
			for(int i=0; i<N; i++) {
				String str=br.readLine();
				for(int j=0; j<N; j++) {
					map[i][j]=str.charAt(j)-'0';
					dp[i][j]=Integer.MAX_VALUE;
				}
			}
			
			dp[0][0]=0;
			
			q.add(new int[] {0,0});
			
			while(!q.isEmpty()) {
				int[] coord=q.poll();
				int x=coord[0];
				int y=coord[1];
				
				for(int i=0; i<4; i++) {
					int nx=x+dx[i];
					int ny=y+dy[i];
					
					
					// 해당 좌표가 범위 안이면
					if(isRange(nx, ny)) {
						if(dp[nx][ny]>dp[x][y]+map[x][y]) {
							dp[nx][ny]=dp[x][y]+map[x][y];
							q.add(new int[] {nx,ny});
						}
					}
					
					
				}
			}
			sb.append("#").append(tc).append(" ").append(dp[N-1][N-1]).append("\n");
			
		}
		
		System.out.println(sb);
	}

	private static boolean isRange(int nx, int ny) {
		if(nx>=0 && nx<N && ny>=0 && ny<N) return true;
		return false;
	}
}