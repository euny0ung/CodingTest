import java.util.Scanner;

public class Main {
	
	static int N;
	static int [][]arr;
	static int x, y;
	static int cnt;
	
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		
		N=sc.nextInt();

		arr=new int[100][100];
		
		for(int i=0; i<N; i++) {
			x=sc.nextInt();
			y=sc.nextInt();
			for(int j=x; j<x+10; j++) {
				for(int z=y; z<y+10; z++) {
					if(arr[j][z]==0) {
						arr[j][z]=1;
						cnt++;
					}
				}
			}
		}
		
		System.out.println(cnt);
	}
}