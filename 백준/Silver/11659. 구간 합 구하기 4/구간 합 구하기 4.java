import java.util.Scanner;

/*
 * N개의 배열을 만들어 1~2, 1~3, 1~4 ... 1~5까지의 값을 저장해두기
 * 구간이 주어지면 저장된 값을 뽑아서 쓰기
 */

public class Main {

	static int N, M, i, j, idx;
	static int input;
	static int []arr;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		
		N=sc.nextInt();
		M=sc.nextInt();
		
		arr=new int[N];


		arr[0]=sc.nextInt();

		
		for(int i=1; i<N; i++) {
			input=sc.nextInt();
			// 기존값 더하기 현재값
			arr[i]=arr[i-1]+input;
		}
		
		
		for(int k=0; k<M; k++) {
			i=sc.nextInt();
			j=sc.nextInt();
			if(i>1) {
				System.out.println(arr[j-1]-arr[i-2]);
			}
			else System.out.println(arr[j-1]);
		}
		
	}

}