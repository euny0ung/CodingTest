import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 전처리를 이용하여 값 비교

public class Main {
	
	static int n,m;
	static int input;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine());
		
		n=Integer.parseInt(st.nextToken());
		m=Integer.parseInt(st.nextToken());
		
		int[] arr=new int[m];
		String[] ans=new String[n];
		
		int cnt=0;
		
		for(int i=0; i<n; i++) {
			StringBuilder sb=new StringBuilder();
			st=new StringTokenizer(br.readLine());
			for(int j=0; j<m; j++) {
				input=Integer.parseInt(st.nextToken());
				arr[j]=input;
			}
			
			for(int j=0; j<m-1; j++) {
				for(int k=j+1; k<m; k++) {
					int result=arr[j]-arr[k];
					if(result<0) sb.append("+");
					else if(result>0) sb.append("-");
					else if(result==0) sb.append("=");
				}
			}
			ans[i]=sb.toString();
		
		}
		
		for(int i=0; i<n-1; i++) {
			for(int j=i+1; j<n; j++) {
				if(ans[i].equals(ans[j])) {
					cnt++;
				}
			}
		}
		
		System.out.println(cnt);
	}
}