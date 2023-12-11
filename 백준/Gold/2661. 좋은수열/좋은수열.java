import java.util.Scanner;

public class Main {
	
	static int N;
	
	public static void main(String[] args) {
		
		Scanner sc=new Scanner(System.in);
		
		N=sc.nextInt();
		
		// 하나씩 더해가기
		backtracking("");
		
	}

	public static void backtracking(String str) {
		
		if(str.length()==N) {
			System.out.println(str);
			System.exit(0);
		}
		
		// 1부터 3까지 하나씩 넣어보기. 작은 수 부터 넣으므로 항상 최소일수밖에 없음
		for(int i=1; i<=3; i++) {
			if(isCondition(str+i)) backtracking(str+i);
		}
		
		
	}

	public static boolean isCondition(String str) {
		// TODO Auto-generated method stub
		
		for(int i=1; i<=str.length()/2; i++) {
			String front = str.substring(str.length()-i*2, str.length()-i);
			String back=str.substring(str.length()-i, str.length());
			
			if(front.equals(back)) return false;
			
		}
		return true;
	}
}