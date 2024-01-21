import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int N,M;
	static int store;
	static int x,y;
	static int[] arr;
	static int sum;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine());
				
		// N이 가로, M이 세로
		N=Integer.parseInt(st.nextToken());
		M=Integer.parseInt(st.nextToken());
		store=Integer.parseInt(br.readLine());
		arr=new int[store+1];
		
		int total_len=(N+M)*2;
		
		
		for(int i=0; i<store+1; i++) {
			st=new StringTokenizer(br.readLine());
			x=Integer.parseInt(st.nextToken());
			y=Integer.parseInt(st.nextToken());
			
			
			switch(x) {
				case 1:
					arr[i]=y;
					break;
				case 2:
					arr[i]=N+M+N-y;
					break;
				case 3:
					arr[i]=N+M+N+M-y;
					break;
				case 4:
					arr[i]=N+y;
					break;
			}
		}
		
		for(int i=0; i<store; i++) {
			int diff=Math.abs(arr[store]-arr[i]);
			sum+=Math.min(total_len-diff, diff);
		}
	
		System.out.println(sum);
		

	}

}