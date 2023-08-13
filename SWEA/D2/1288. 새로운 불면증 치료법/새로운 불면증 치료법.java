import java.util.Scanner;

public class Solution {

	static int N;
	static int result;
	static int sheepNum;
	static int testCase;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc =new Scanner(System.in);
		
		testCase=sc.nextInt();
		
		result=(1<<10)-1;
		
		for(int i=1; i<=testCase; i++) {
			N=sc.nextInt();
			
			
			int cnt=0;
			sheepNum=0;
			
			for(cnt=1;; cnt++) {
				char []arr=String.valueOf(N*cnt).toCharArray();
				for(char ch : arr) {
					int num=ch-'0';
					sheepNum=sheepNum | (1<<num);
				}
				if(result==sheepNum) break;
			}
			System.out.println("#"+i+" "+N*cnt);	
		}
	}

}