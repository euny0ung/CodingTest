import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int N,M;
	static int r,c,s;
	static int calNum;
	static int [][]arr;
	static int [][]tempArr;
	static int [][]cal;
	static int result=Integer.MAX_VALUE;

	// 하 우 상 좌
	static int []dx= {1,0,-1,0};
	static int []dy= {0,1,0,-1};
	
	// 순열
	static int []pick;
	static boolean []isSelected;
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine());
		
		N=Integer.parseInt(st.nextToken());
		M=Integer.parseInt(st.nextToken());
		
		arr=new int[N][M];
		tempArr = new int[N][M];
		calNum=Integer.parseInt(st.nextToken());
		
		cal=new int[calNum][3];
		pick=new int[calNum];
		isSelected=new boolean[calNum];
		
		for(int i=0; i<N; i++) {
			st=new StringTokenizer(br.readLine());
			for(int j=0; j<M; j++) {
				arr[i][j]=Integer.parseInt(st.nextToken());
			}
		}
		
		// 수행할 연산 입력
		for(int i=0; i<calNum; i++) {
			st=new StringTokenizer(br.readLine());
			for(int j=0; j<3; j++) {
				int calInput=Integer.parseInt(st.nextToken());
				
				cal[i][j]=calInput;
			}
		
		}
		
		perm(0);
		
		System.out.println(result);
	}
	
	// 순열을 만드는 함수 (0~calNum-1까지 돌리고 나온 수로 cal 배열 이용)
	static void perm(int cnt) {
		if(cnt==calNum) {
			
			for(int i=0; i<N; i++) {
				System.arraycopy(arr[i], 0, tempArr[i], 0, arr[i].length);
			}
			
			// 연산 횟수만큼 수행
			for(int i=0; i<cnt; i++) {
				r=cal[pick[i]][0];
				c=cal[pick[i]][1];
				s=cal[pick[i]][2];
				
				
				// 연산 수행하는 함수 호출
				
				calFunc(r-s, c-s, r+s, c+s);
				
//				
			}
			
			// 각 행의 모든 수의 합을 더하고 가장 작은 값 갱신
			for(int i=0;i<N; i++) {
				int min=0;
				for(int j=0; j<M; j++) {
					min+=tempArr[i][j];
				}
				result=Math.min(result, min);
			}
			
		}
		else {
			for(int i=0; i<calNum; i++) {
				if(!isSelected[i]) {
					pick[cnt]=i;
					isSelected[i]=true;
					perm(cnt+1);
					isSelected[i]=false;
				}
			}
		}
	}
	
	// 연산을 수행하는 함수
	
	static void calFunc(int xFirstIdx, int yFirstIdx, int xLastIdx, int yLastIdx) {

		//배돌..
		for(int i=0; i<Math.min(xLastIdx-xFirstIdx, yLastIdx-yFirstIdx)/2; i++) {
			int temp=tempArr[xFirstIdx-1+i][yFirstIdx-1+i];
			int prevXpos=xFirstIdx+i-1;
			int prevYpos=yFirstIdx+i-1;
			int idx=0;
			
			
			while(idx<4) {
				int nx=prevXpos+dx[idx];
				int ny=prevYpos+dy[idx];
				
				// 범위 안이면 이전 값을 다음 값으로 밀어주고 이전인덱스=다음 인덱스
				if(nx>=xFirstIdx-1+i && nx<xLastIdx-i && ny>=yFirstIdx-1+i && ny<yLastIdx-i) {
					// 인덱스에는 문제가 없음. 다음값을 저장 안하고 계속 밀어쓰니까 똑같은 수가 들어가는 것
					
					tempArr[prevXpos][prevYpos]=tempArr[nx][ny];
				
					prevXpos=nx;
					prevYpos=ny;
				}
				else {
					idx++;
				}
				
				
			}
			// 마지막 값 넣어주기
			tempArr[prevXpos][prevYpos+1]=temp;
			
		}
		
	}

}