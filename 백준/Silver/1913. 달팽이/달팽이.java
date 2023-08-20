import java.util.Scanner;

public class Main {

	static int N;
	static int x,y,nx,ny;
	static int input;
	static int idx;
	static int searchNum;
	static int searchX, searchY;
	static int [][]arr;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		StringBuilder sb=new StringBuilder();
		
		N=sc.nextInt();
		searchNum=sc.nextInt();
		arr=new int[N][N];
		
		int []dx= {1,0,-1,0};
		int []dy= {0,1,0,-1};
		
		for(int i=N*N; i>0; i--) {
			
			arr[x][y]=i;
			
			if(i==searchNum) {
				searchX=x;
				searchY=y;
			}
			// 다음 좌표가 범위를 넘었거나 다음 좌표의 값이 0이 아니면 방향 전환
			nx=x+dx[idx];
			ny=y+dy[idx];
			
			if(!isRange(nx, ny, N) || arr[nx][ny]!=0) {
				idx=(idx+1)%4;
			}
			// 현재좌표 업데이트
			x+=dx[idx];
			y+=dy[idx];
		}
		
		for(int []a: arr) {
			for(int b:a) {
				sb.append(b+" ");
			}
			sb.append("\n");
		}
		
		sb.append((searchX+1)+" "+(searchY+1));
		
		System.out.println(sb);
	}
	
	static boolean isRange(int x, int y, int n) {
		return (x>=0 && x<n && y>=0 && y<n);
	}

}