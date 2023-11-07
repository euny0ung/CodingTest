import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;



public class Main {

	static int N,M;
	static int[] nArr;
	static int[] mArr;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine());
		
		N=Integer.parseInt(st.nextToken());
		M=Integer.parseInt(st.nextToken());
		
		nArr=new int[N];
		mArr=new int[M];
		
		st=new StringTokenizer(br.readLine());
		
		for(int i=0; i<N; i++) {
			nArr[i]=Integer.parseInt(st.nextToken());
		}
		Arrays.sort(nArr);
		
		// N개 중에 M개 뽑기 (중복조합)
		perm(0, 0);
	}

	private static void perm(int idx, int start) {
		
		if(idx==M) {
			for(int i=0; i<M; i++) {
				System.out.print(mArr[i]+" ");
			}
			System.out.println();
			return;
		}
		for(int i=start; i<N; i++) {
				mArr[idx]=nArr[i];
				perm(idx+1, i);
				
		}
		
	}
}