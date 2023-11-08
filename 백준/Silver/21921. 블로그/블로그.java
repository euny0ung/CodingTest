import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int N,X, sum, max, cnt;
	static int[] arr;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine());
		
		N=Integer.parseInt(st.nextToken());
		X=Integer.parseInt(st.nextToken());
		arr=new int[N];
		
		st=new StringTokenizer(br.readLine());
		
		for(int i=0; i<N; i++) {
			arr[i]=Integer.parseInt(st.nextToken());
		}
		
		for(int i=0; i<X; i++) {
			sum+=arr[i];
		}
		
		max=sum;
		cnt=1;
		
		for(int i=X; i<N; i++) {
			sum+=arr[i]-arr[i-X];
			if(max==sum) cnt++;
			else if(max < sum) {
				max=sum;
				cnt=1;
			}
			
		}
		
		
		
		if(max==0) System.out.println("SAD");
		else {
			System.out.println(max);
			System.out.println(cnt);
		}
		
		
	}
}