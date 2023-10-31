import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int N, M;
	static int[][] arr;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st=new StringTokenizer(br.readLine());
		
		N=Integer.parseInt(st.nextToken());
		M=Integer.parseInt(st.nextToken());
		arr=new int[N][M];
		
		int len=Math.min(N, M);
		
		for(int i=0; i<N; i++) {
			String str=br.readLine();
			for(int j=0; j<M; j++) {
				arr[i][j]=str.charAt(j)-'0';
			}
		}
		
		while(len!=0) {
			for(int i=0; i<=N-len; i++) {
				for(int j=0; j<=M-len; j++) {
					 int num=arr[i][j];
					 
					 // 꼭짓점 비교
					 if(num==arr[i][j+len-1] && num==arr[i+len-1][j] && num==arr[i+len-1][j+len-1]) {
						 System.out.println(len*len);
						 return;
					 }
				}
			}
			len--;
		}
		
		System.out.println(len*len);
		
	}
}