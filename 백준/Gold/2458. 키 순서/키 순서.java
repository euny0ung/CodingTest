import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int N,M;
	static int[][] arr;
	static int result;
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st=new StringTokenizer(br.readLine());
		
		int maxValue=987_654_321;
		
		N=Integer.parseInt(st.nextToken());
		M=Integer.parseInt(st.nextToken());
		
		arr=new int[N+1][N+1];
		
		
		// 자기 자신을 제외한 모든 노드를 maxValue로 초기화
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=N; j++) {
				if(i!=j) arr[i][j]=maxValue;
			}
		}
		
		// 노드 연결
		for(int i=1; i<=M; i++) {
			st=new StringTokenizer(br.readLine());
			int a=Integer.parseInt(st.nextToken());
			int b=Integer.parseInt(st.nextToken());
			
			arr[a][b]=1;
		}
		
		// 플로이드 워샬 i는 중간지점, j는 출발지점, k는 도착지점
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=N; j++) {
				for(int k=1; k<=N; k++) {
					if(arr[j][i]+arr[i][k]<arr[j][k]) arr[j][k]=1;
				}
			}
		}
		
		// 전체를 탐색하며 1이 얼마나 있는지 확인하기. 자기 자신은 제외해야하므로 N-1개가 나오면 자신의 키가 몇번째인지 알 수 있음
		for(int i=1; i<=N; i++) {
			int cnt=0;
			for(int j=1; j<=N; j++) {
				if(arr[i][j]==1 || arr[j][i]==1) cnt++;
			}
			if(cnt==N-1) result++;
		}
		
		System.out.println(result);
	}

}