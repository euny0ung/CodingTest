import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static int[][] arr;
	static int[][] temp;
	static int R,C,T;
	static int firstX, secondX;
	static Queue<Integer>cleaner;
	
	static int[] dx= {1,-1,0,0};
	static int[] dy= {0,0,1,-1};
	
	public static void main(String[] args) throws IOException {

		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine());
		
		R=Integer.parseInt(st.nextToken());
		C=Integer.parseInt(st.nextToken());
		T=Integer.parseInt(st.nextToken());
		
		arr=new int[R][C];
		cleaner=new ArrayDeque<>();
		
		for(int i=0; i<R; i++) {
			st=new StringTokenizer(br.readLine());
			for(int j=0; j<C; j++) {
				arr[i][j]=Integer.parseInt(st.nextToken());
				if(arr[i][j]==-1) cleaner.add(i); // 항상 1번 열에 설치되어있으므로 행값만 필요
			}
		}
		
		int firstX=cleaner.poll();
		int secondX=cleaner.poll();
		
		for(int i=0; i<T; i++) {
			// 확산
			arr=spread(firstX, secondX);
			
			
			
			// 공청기 작동
			cleanerOn(firstX, secondX);
			
//			for(int k=0; k<R; k++) {
//				for(int j=0; j<C; j++) {
//					System.out.print(arr[k][j]);
//				}
//				System.out.println();
//				
//			}System.out.println("======================");
		}
		
		
		
		int result=0;
		
		for(int i=0; i<R; i++) { 
			for(int j=0; j<C; j++) {
				if(arr[i][j]>0) result+=arr[i][j];
			} 
		}
		
		System.out.println(result);
		 
	}

	private static void cleanerOn(int firstX, int secondX) {
	
		// 공청기 윗부분 작동
		firstCleanerOn(firstX);
		
		// 공청기 아랫부분 작동
		secondCleanerOn(secondX);
	}
	
	private static void firstCleanerOn(int x) {
		
		// 왼쪽
		for(int i=x-1; i>0; i--) {
			arr[i][0]=arr[i-1][0];
		}
		
		// 윗변 (오 -> 왼)
		for(int i=0; i<C-1; i++) {
			arr[0][i]=arr[0][i+1];
		}
		
		// 우측
		for(int i=0; i<x; i++) {
			arr[i][C-1]=arr[i+1][C-1];
		}
		
		// 아랫변
		for(int i=C-1; i>1; i--) {
			arr[x][i]=arr[x][i-1];
		}
		
		arr[x][1]=0;
		
	}
	
	private static void secondCleanerOn(int x) {
		
		// 왼쪽
		for(int i=x+1; i<R-1; i++) {
			arr[i][0]=arr[i+1][0];
		}
		
		// 아랫변
		for(int i=0; i<C-1; i++) {
			arr[R-1][i]=arr[R-1][i+1];
		}
		
		// 우측
		for(int i=R-1; i>x; i--) {
			arr[i][C-1]=arr[i-1][C-1];
		}
		
		// 윗변
		for(int i=C-1; i>1; i--) {
			arr[x][i]=arr[x][i-1];
		}
		
		arr[x][1]=0;
		
	}

	

	private static int[][] spread(int firstX, int secondX) {
		
		temp=new int[R][C];
		temp[firstX][0]=-1;
		temp[secondX][0]=-1;
		
		
		for(int x=0; x<R; x++) {
			for(int y=0; y<C; y++) {
				
				if(arr[x][y]==-1) continue;
				temp[x][y]+=arr[x][y];
				
				int spreadValue=arr[x][y]/5;
			
				for(int i=0; i<4; i++) {
					int nx=x+dx[i];
					int ny=y+dy[i];
					
					if(isRange(nx,ny) && arr[nx][ny]!=-1) {
						temp[nx][ny]+=spreadValue;
						temp[x][y]-=spreadValue;
					}
				}
			}
		}
			
			
		return temp;
		
		
	}

	private static boolean isRange(int nx, int ny) {
		if(nx>=0 && nx<R && ny>=0 && ny<C) return true;
		return false;
	}
}