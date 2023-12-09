import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	
	static int n, s;
	static int[][] arr;
	static boolean[] picked;
	static int min;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine());
		
		n=Integer.parseInt(st.nextToken());
		
		min=Integer.MAX_VALUE;
		
		arr=new int[n][n];
		picked=new boolean[n];
		
		for(int i=0; i<n; i++) {
			st=new StringTokenizer(br.readLine());
			for(int j=0; j<n; j++) {
				arr[i][j]=Integer.parseInt(st.nextToken());
			
			}
		}
		
		comb(0,0);
		
		System.out.println(min);
		
	}

	public static void comb(int cnt, int start) {
		if(cnt==n/2) {

			calc();
			
			return;
		}
		
		for(int i=start; i<n; i++) {
			picked[i]=true;
			comb(cnt+1, i+1);
			picked[i]=false;
		}
		
	}

	public static void calc() {
		int start=0;
		int link=0;
		
		for(int i=0; i<n-1; i++) {
			for(int j=i+1; j<n; j++) {
				if(picked[i]==true && picked[j]==true) {
					start+=arr[i][j];
					start+=arr[j][i];
				}
				if(picked[i]==false && picked[j]==false) {
					link+=arr[i][j];
					link+=arr[j][i];
				}
			}
		}
		
		int result=Math.abs(start-link);
		
		min=Math.min(min, result);
		
	}
	
	
}