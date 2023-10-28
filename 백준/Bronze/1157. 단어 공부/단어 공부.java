import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	
	static int[] arr;
	
	public static void main(String[] args) throws IOException {
		String str=" ";
		arr=new int[26];
		
		int max=0, idx=0;
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		str=br.readLine().toUpperCase();
		
		for(int i=0; i<str.length(); i++) {
			
			int input=str.charAt(i)-'A';
			arr[input]++;
		}
		
		// 배열 최대값 구하기
		for(int i=0; i<26; i++) {
			if(max<arr[i]) {
				max=arr[i];
				idx=i;
			}
		}
		
		int cnt=0;
		
		for(int i=0; i<26; i++) {
			if(arr[i]==max) {
				
				cnt++;
			}
		}
		
		if(cnt!=1) System.out.println("?");
		else System.out.println((char)(idx+65));
		
	}
}