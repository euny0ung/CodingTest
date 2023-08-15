import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static char [][]arr;
	static int startX, startY;
	static StringBuilder sb=new StringBuilder();
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine());
		
		
		N=Integer.parseInt(st.nextToken());
		
		arr=new char[N][N];
		
		for(int i=0; i<N; i++) {
			String n=br.readLine();
			for(int j=0; j<N; j++) {
				arr[i][j]=n.charAt(j);
			
			}
			
		}
		divide(0,0,N);
		System.out.println(sb);
	}
	
	static void divide(int startX, int startY, int N) {
		
		// 체크 결과 모두 0이거나 1이 아니면 쪼개주기
		if(check(startX, startY, N)) {
			sb.append(arr[startX][startY]);
			return;
		}
		
		int size=N/2;
		
		sb.append("(");
		
		divide(startX, startY, size);
		divide(startX, startY+size, size);
		divide(startX+size, startY, size);
		divide(startX+size, startY+size, size);
		
		sb.append(")");		
	}
	
	
	
	static boolean check(int startX, int startY, int size) {
		
		// 어차피 0이거나 1이므로 하나 뽑아서 비교하면 됨
		char tempCh=arr[startX][startY];
		
		for(int i=startX; i<startX+size; i++) {
			for(int j=startY; j<startY+size; j++) {
				if(tempCh!=arr[i][j]) {
					return false;
				}
			}
		}
		return true;
	}
	

}