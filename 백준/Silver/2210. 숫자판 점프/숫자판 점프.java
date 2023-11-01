import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main {
	static boolean[] visited;
	static int[][] arr;
	static int ans;
	
	static int[] dx= {0,0,1,-1};
	static int[] dy= {1,-1,0,0};
	
	public static void dfs(int x, int y, int sum, int cnt) {
		// cnt가 5이 되면 멈춤
		if(cnt==5) {
			// 기존에 없는 숫자면 count
			if(!visited[sum]) {
				visited[sum]=true;
				ans++;
			}
			return;
		}
		// 다음 좌표가 범위 내면 dfs
		
		for(int i=0; i<4; i++) {
			int nx=x+dx[i];
			int ny=y+dy[i];
			
			if(isRange(nx, ny)) {
				dfs(nx, ny, arr[nx][ny]+(sum*10), cnt+1);
			}
		}
	}
	
	private static boolean isRange(int nx, int ny) {
		if(nx>=0 && nx<5 && ny>=0 && ny<5) return true;
		return false;
	}

	public static void main(String[] args) throws IOException {
		visited=new boolean[1000000];
		arr=new int[5][5];
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		for(int i=0; i<5; i++) {
			st=new StringTokenizer(br.readLine());
			for(int j=0; j<5; j++) {
				arr[i][j]=Integer.parseInt(st.nextToken());
			}
		}
		
		// 모든 좌표에서 dfs
		for(int i=0; i<5; i++) {
			for(int j=0; j<5; j++) {
				dfs(i, j, arr[i][j], 0);
			}
		}
		System.out.println(ans);
	}
}