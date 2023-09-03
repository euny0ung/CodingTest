import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		int n=0, m=0;
		int o=0;
		int x;
		
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine());
		StringBuilder sb=new StringBuilder();
		
		n=Integer.parseInt(st.nextToken());
		m=Integer.parseInt(st.nextToken());
		
		String str;
		int al=0;
		
		int alphabet=(1<<27)-1;
	
		int[] arr=new int[n];
		
		for(int i=0; i<n; i++) {
			str=br.readLine();
			for(int j=0; j<str.length(); j++) {
				al=str.charAt(j)-'a';
				arr[i]=arr[i]|(1<<al);
			
			}
		}
		
		for(int i=0; i<m; i++) {
			int cnt=0;
			st=new StringTokenizer(br.readLine());
			o=Integer.parseInt(st.nextToken());
			x=st.nextToken().charAt(0)-'a';
			
			if(o==1) {
				alphabet=alphabet&~(1<<x);
			}
			else {
				alphabet=alphabet|(1<<x);
			}
			
			for(int ele: arr) {
				if((alphabet&ele)>=ele) cnt++;
			}
			sb.append(cnt).append("\n");
		}
		
		System.out.println(sb);
	}
}