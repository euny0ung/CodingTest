import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int C, P;
	static int height;
	static int[] arr;
	static int ans;

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine());
		
		C=Integer.parseInt(st.nextToken());
		P=Integer.parseInt(st.nextToken());
		
		arr=new int[C];
		
		st=new StringTokenizer(br.readLine());
		for(int i=0; i<C; i++) {
			arr[i]=Integer.parseInt(st.nextToken());
		}
		
		switch(P) {
		case 1:
			ans+=C;
			for(int i=0; i<C-3; i++) {
				if(arr[i]==arr[i+1]&& arr[i+1]==arr[i+2]&& arr[i+2]==arr[i+3]) ans++;
			}
			break;
		case 2:
			for(int i=0; i<C-1; i++) {
				if(arr[i]==arr[i+1]) ans++;
			}
			break;
		case 3:
			// 첫번째 케이스
			for(int i=0; i<C-2; i++) {
				if(arr[i]==arr[i+1] && arr[i+1]==arr[i+2]-1) ans++;
			}
			// 두번째 케이스
			for(int i=0; i<C-1; i++) {
				if(arr[i]==arr[i+1]+1) ans++;
			}
			break;
		case 4:
			for(int i=0; i<C-2; i++) {
				if(arr[i]-1==arr[i+1] && arr[i+1]==arr[i+2]) ans++;
			}
			for(int i=0; i<C-1; i++) {
				if(arr[i]+1==arr[i+1]) ans++;
			}
			break;
		case 5:
			// 첫번째 케이스
			for(int i=0; i<C-2; i++) {
				if(arr[i]==arr[i+1]&& arr[i+1]==arr[i+2]) ans++;
			}
			
			// 두번째 케이스
			for(int i=0; i<C-1; i++) {
				if(arr[i]+1==arr[i+1]) ans++;
			}
			// 세번째 케이스
			for(int i=0; i<C-2; i++) {
				if(arr[i]==arr[i+1]+1 && arr[i+1]+1==arr[i+2]) ans++;
			}
			// 네번째 케이스
			for(int i=0; i<C-1; i++) {
				if(arr[i]==arr[i+1]+1) ans++;
			}
			break;
		case 6:
			for(int i=0; i<C-2; i++) {
				if(arr[i]==arr[i+1] && arr[i+1]==arr[i+2]) ans++;
			}
			for(int i=0; i<C-1; i++) {
				if(arr[i]==arr[i+1]) ans++;
			}
			for(int i=0; i<C-2; i++) {
				if(arr[i]+1==arr[i+1] && arr[i+1]==arr[i+2]) ans++;
			}
			for(int i=0; i<C-1; i++) {
				if(arr[i]-2==arr[i+1]) ans++;
			}
			break;
		case 7:
			for(int i=0; i<C-2; i++) {
				if(arr[i]==arr[i+1]&& arr[i+1]==arr[i+2]) ans++;
			}
			for(int i=0; i<C-1; i++) {
				if(arr[i]+2==arr[i+1]) ans++;
			}
			for(int i=0; i<C-2; i++) {
				if(arr[i]==arr[i+1]&&arr[i+1]==arr[i+2]+1) ans++;
			}
			for(int i=0; i<C-1; i++) {
				if(arr[i]==arr[i+1]) ans++;
			}
			break;
		default:
			break;
		}
		System.out.println(ans);
	}

}