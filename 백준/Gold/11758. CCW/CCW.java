import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int[] x;
	static int[] y;
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		x=new int[3];
		y=new int[3];
		
		for(int i=0; i<3; i++) {
			st=new StringTokenizer(br.readLine());
			x[i]=Integer.parseInt(st.nextToken());
			y[i]=Integer.parseInt(st.nextToken());
			
		}
		
		int result=x[1]*y[2]-x[2]*y[1]+x[2]*y[0]-x[0]*y[2]+x[0]*y[1]-x[1]*y[0];
		
		if(result>0) System.out.println("1");
		else if(result==0) System.out.println("0");
		else System.out.println("-1");
		
	}
	
	
}