import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;


public class Main {
	
	static int[][] arr;
	static List<int[]>list;
	
	public static void main(String[] args) throws IOException {
		
		arr=new int[9][9];
		list=new ArrayList<>();
		
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		for(int i=0; i<9; i++) {
			char[] line = br.readLine().toCharArray();
			for(int j=0; j<9; j++) {
				arr[i][j]=line[j]-'0';
				if(arr[i][j]==0) {
					
					list.add(new int[] {i,j});
					/* System.out.println(i+" "+j); */
					
				}
			}
		
		}
	
		go(0);
		
	}
	
	private static void go(int level) {
		
		
		
		// 만약 level이랑 list 사이즈랑 같다면 종료
		if(list.size()==level) {
			for(int i=0; i<9; i++) {
				for(int j=0; j<9; j++) {
					System.out.print(arr[i][j]);
				}
				System.out.println();
			}
			System.exit(0);
			return;
		}
		
		// 만약 arr[i][j]를 채울 수를 찾는다고 하면 arr[i][0~9], arr[0~9][j], 3x3 검사
		
				int x=list.get(level)[0];
				int y=list.get(level)[1];
				
				boolean[] checked=new boolean[10];
				
				for(int i=0; i<9; i++) {
					
					// 가로
					if(arr[x][i]!=0) {
						// 0이 아닌 수는 체크
						checked[arr[x][i]]=true;
					}
					

					
					// 세로
					if(arr[i][y]!=0) {
						checked[arr[i][y]]=true;
					}

				}
				
				// 3x3
				int xRange= x/3*3;
				int yRange= y/3*3;
				
				for(int i=xRange; i<xRange+3; i++) {
					for(int j=yRange; j<yRange+3; j++) {
						if(arr[i][j]!=0) {
							checked[arr[i][j]]=true;
						}
						
					}
				}
				
			
				
				
				for(int i=1; i<10; i++) {
					
					// false면 없는 수
					if(!checked[i]) {
						
						arr[x][y]=i;
						go(level+1);
						arr[x][y]=0;
					}
				}
			
		
		
		
	}
	
	
	
	
}