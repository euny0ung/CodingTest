import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
	
	static int N,M;
	static int x1, y1, x2, y2;
	static int [][]arr;
	static int [][]result;
	
	public static void main(String[] args) throws IOException {
		Scanner sc=new Scanner(System.in);
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine());
		StringBuilder sb=new StringBuilder();
		
		N=Integer.parseInt(st.nextToken());
		M=Integer.parseInt(st.nextToken());
		
		arr=new int[N+1][N+1];
		result=new int[N+1][N+1];

		
		for(int i=1; i<=N; i++) {
			st=new StringTokenizer(br.readLine());
			for(int j=1; j<=N; j++) {
				arr[i][j]=Integer.parseInt(st.nextToken());
				
			}
		}
		
		// 합 구하기
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=N; j++) {
				result[i][j]=result[i-1][j]+result[i][j-1]-result[i-1][j-1]+arr[i][j];
				
			}
		}
		
		for(int i=1; i<=M; i++) {
			st=new StringTokenizer(br.readLine());
			x1=Integer.parseInt(st.nextToken());
			y1=Integer.parseInt(st.nextToken());
			x2=Integer.parseInt(st.nextToken());
			y2=Integer.parseInt(st.nextToken());
			int answer=result[x2][y2]-result[x2][y1-1]-result[x1-1][y2]+result[x1-1][y1-1];
			sb.append(answer+"\n");
		}
		System.out.println(sb);
		
	}
}