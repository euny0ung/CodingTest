import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class Main {
	
	static int N;
	static int[] arr;
	static List<Integer>list;
	
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		
		N=sc.nextInt();
		arr=new int[N];
		list=new ArrayList<Integer>();
		
		int answer=0;
		
		for(int i=0; i<N; i++) {
			arr[i]=sc.nextInt();
		}
		int temp=0;
		
		for(int i=1; i<N; i++) {
			if(arr[i-1]<arr[i]) {
				temp+=(arr[i]-arr[i-1]);
			}
			else temp=0;
			answer=Math.max(answer, temp);
		}
		
		System.out.println(answer);
	}
}