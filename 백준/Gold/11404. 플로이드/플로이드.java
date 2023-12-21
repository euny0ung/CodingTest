import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N, M;
	static int[][] arr;
	static int a, b, c;
	static int INF=987_654_321;
	
	public static void main(String[] args) throws NumberFormatException, IOException  {
		// TODO Auto-generated method stub
		
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringBuffer sb= new StringBuffer();
		
		N=Integer.parseInt(br.readLine());
		M=Integer.parseInt(br.readLine());
		
		arr=new int[N+1][N+1];
		
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=N; j++) {
				
				// 출발 도시와 도착 도시가 다른 경우에만
				if(i!=j) {
						arr[i][j]=INF;
				
				}
			}
		}
		
		for(int i=0; i<M; i++) {
			StringTokenizer st=new StringTokenizer(br.readLine());
			
			a=Integer.parseInt(st.nextToken());
			b=Integer.parseInt(st.nextToken());
			c=Integer.parseInt(st.nextToken());
			
			arr[a][b]=Math.min(arr[a][b], c);
		}
		
		// j는 출발, k는 도착, i는 거쳐가는 곳. 순서 바뀌면 답 달라짐. i를 출발 k를 도착으로 했다가 답 약간 다르게 나옴
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=N; j++) {
				for(int k=1; k<=N; k++) {
					if(arr[j][i]+arr[i][k]<arr[j][k]) {
						arr[j][k]=arr[j][i]+arr[i][k];
					}
				}
			}
		}
		
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=N; j++) {
				if(arr[i][j]==INF) arr[i][j]=0;
				sb.append(arr[i][j] +" ");
			}
			sb.append("\n");
		}
		
		System.out.println(sb);
	}

}