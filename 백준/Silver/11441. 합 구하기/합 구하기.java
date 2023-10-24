import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main {

	static int N, M, a, b;
	static int[] arr;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb=new StringBuilder();
		
		N=Integer.parseInt(br.readLine());
		arr=new int[N+1];
		
		StringTokenizer st=new StringTokenizer(br.readLine());
		
		for(int i=1; i<N+1; i++) {
			arr[i]=Integer.parseInt(st.nextToken());
		}
		
		for(int i=2; i<N+1; i++) {
			arr[i]+=arr[i-1];
		}
		
		M=Integer.parseInt(br.readLine());
		
		for(int i=0; i<M; i++) {
			st=new StringTokenizer(br.readLine());
			a=Integer.parseInt(st.nextToken());
			b=Integer.parseInt(st.nextToken());
			
			int result=arr[b]-arr[a-1];
			sb.append(result).append("\n");
		}
		
		
		System.out.println(sb);
		
		
	}

}