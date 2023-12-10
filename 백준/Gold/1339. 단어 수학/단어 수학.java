import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;


public class Main {
	
	static int N;
	static String str;
	static int[] arr;
	static int result;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		N=Integer.parseInt(br.readLine());
		
		arr=new int[26];
		
		for(int i=0; i<N; i++) {
			str=br.readLine();
			
			for(int j=0; j<str.length(); j++) {
				char c=str.charAt(j);
				arr[c-'A']+=(int)Math.pow(10, str.length()-1-j);
			}
		}
		
		
		
		Arrays.sort(arr);
	
		int num=9;
		
		for(int i=25; i>=0; i--) {
			if(arr[i]!=0) {
				result+=arr[i]*num;
				
				num--;
			}
		}
		
		System.out.println(result);
		
	}
}