import java.util.Scanner;


public class Main {

	static int N;
	static int result;
	static int pick;
	
	static StringBuilder sb=new StringBuilder();
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc=new Scanner(System.in);

		N=sc.nextInt();
		
		comb(0, N);

		
		System.out.println(sb);
	}
	
	static void comb(int result, int N) {
	
		if(N==0) {
			// 수를 완성하고 다시 소수 검사
			if(isPrimitive(result)) {
				sb.append(result).append("\n");
				return;
			}
			
		}
		
		for(int i=0; i<10; i++) {	
		
				// 한자리수 늘려주기
				int next=result*10+i;

				// 새로 만든 숫자가 소수면
				if(isPrimitive(next)) {
					
					// 그 다음 자리수 탐색
					comb(next, N-1);
				}
			}
	
			
			
	
	}
	
	
	// 소수 검사
	static boolean isPrimitive(int result) {
		
		if(result<2) return false;

		for(int i=2; i<=Math.sqrt(result); i++) {
			if(result%i==0) return false;
		}
		return true;
	}

}