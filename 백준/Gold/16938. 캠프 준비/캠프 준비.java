import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException{
		int num=0;
		int input=0;
		int cnt=0;
		long L=0L, R=0L, X=0L;
		
		List<Integer>list=new ArrayList<>();
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine());
		
		num=Integer.parseInt(st.nextToken());
		L=Integer.parseInt(st.nextToken());
		R=Integer.parseInt(st.nextToken());
		X=Integer.parseInt(st.nextToken());
		
		st=new StringTokenizer(br.readLine());
		
		int[] arr=new int[num];
		for(int i=0; i<num; i++) {
			input=Integer.parseInt(st.nextToken());
			arr[i]=input;
			
		}
		
		for(int i=0; i<(1<<num); i++) {
			long result=0L;
			long minus=0L;
			
			list.clear();
			
			for(int j=0; j<num; j++) {
				if((i&(1<<j))>0) {
					list.add(arr[j]);
					
				}
			}
			
			if(list.size()<2) {
				list.clear();
				continue;
			}
			Collections.sort(list);
			
			for(int j=0; j<list.size(); j++) {
				result+=list.get(j);
			}
		
			minus=list.get(list.size()-1)-list.get(0);
			
			if(result>=L && result<=R && minus>=X) cnt++;
		}
		
		System.out.println(cnt);
	}
}