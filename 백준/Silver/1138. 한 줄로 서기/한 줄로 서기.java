import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int N;
	static int[] arr;
	static int[] ans;

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		StringBuffer sb=new StringBuffer();
		
		N=Integer.parseInt(br.readLine());
		
		arr=new int[N+1];
		ans=new int[N];
		
		StringTokenizer st=new StringTokenizer(br.readLine());
		
		for(int i=1; i<N; i++) {
		
			arr[i]=Integer.parseInt(st.nextToken());
		}
	
		
		for(int i=1; i<N+1; i++) {
			int cnt=0;
			
			// ans의 처음부터 끝까지 다 돌며 검사
			for(int j=0; j<N; j++) {
				if(cnt==arr[i] && ans[j]==0) { 
					ans[j]=i;
					break;
				}
				else if(ans[j]==0)	cnt++;
			}
		}
		
		for(int i=0; i<N; i++) {
			sb.append(ans[i]).append(" ");
		}
		
		System.out.println(sb);
	}

}