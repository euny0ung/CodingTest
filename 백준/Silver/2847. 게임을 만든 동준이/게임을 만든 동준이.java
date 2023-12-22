import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {
	
	static int N, result;
	static int[] arr;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		N=Integer.parseInt(br.readLine());
		
		arr=new int[N];
		
		// 처음부터 거꾸로 입력
		for(int i=N-1; i>=0; i--) {
			arr[i]=Integer.parseInt(br.readLine());
		}
		
		for(int i=0; i<N-1; i++) {
			
			if(arr[i]<=arr[i+1]) {
				result+=arr[i+1]-(arr[i]-1);
				arr[i+1]=arr[i]-1;
		
			}
		}
		
		System.out.println(result);
	}

}