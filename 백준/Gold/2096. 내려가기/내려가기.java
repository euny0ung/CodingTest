import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int N;
	static int[][] arr;
	static int[][] max;
	static int[][] min;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		
		N=Integer.parseInt(br.readLine());
		arr=new int[N][3];
		max=new int[N][3];
		min=new int[N][3];
		
		int max_result=0, min_result=0;
		
		for(int i=0; i<N; i++) {
			StringTokenizer st=new StringTokenizer(br.readLine());
			for(int j=0; j<3; j++) {
				arr[i][j]=Integer.parseInt(st.nextToken());
			
			}
		}
		
		max[0][0]=arr[0][0];
		max[0][1]=arr[0][1];
		max[0][2]=arr[0][2];
		
		min[0][0]=arr[0][0];
		min[0][1]=arr[0][1];
		min[0][2]=arr[0][2];
		
		for(int i=1; i<N; i++) {
			max[i][0]=Math.max(max[i-1][0], max[i-1][1])+arr[i][0];
			max[i][1]=Math.max(max[i-1][0], Math.max(max[i-1][1], max[i-1][2]))+arr[i][1];
			max[i][2]=Math.max(max[i-1][1], max[i-1][2])+arr[i][2];
			min[i][0]=Math.min(min[i-1][0], min[i-1][1])+arr[i][0];
			min[i][1]=Math.min(min[i-1][0], Math.min(min[i-1][1], min[i-1][2]))+arr[i][1];
			min[i][2]=Math.min(min[i-1][1], min[i-1][2])+arr[i][2];
			
		}
		
		max_result=Math.max(max[N-1][0], Math.max(max[N-1][1], max[N-1][2]));
		min_result=Math.min(min[N-1][0], Math.min(min[N-1][1], min[N-1][2]));
		
		System.out.println(max_result+" "+min_result);
	}
}