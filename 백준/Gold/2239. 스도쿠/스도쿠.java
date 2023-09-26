import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;


public class Main {
	static int[][] map;
	static List<int[]> list;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		map=new int[9][9];
		list=new ArrayList<int[]>();
		
		for(int i=0; i<9; i++) {
			String input=br.readLine();
			
			for(int j=0; j<9; j++) {
				map[i][j]=input.charAt(j)-'0';
				
				if(map[i][j]==0) list.add(new int[] {i,j});
			}
		}
		go(0);
	}
	
	private static void go(int level) {
		
		if(list.size()==level) {
			for(int i=0; i<9; i++) {
				for(int j=0; j<9; j++) {
					System.out.print(map[i][j]);
				}
				System.out.println();
			}
			System.exit(0);
		}
		
		int x=list.get(level)[0];
		int y=list.get(level)[1];
		
		boolean[] check=new boolean[10];
		
		for(int i=0; i<9; i++) {
			if(map[x][i]!=0) check[map[x][i]]=true;
			if(map[i][y]!=0) check[map[i][y]]=true;
		}
		
		int xRange=x/3*3;
		int yRange=y/3*3;
		
		for(int i=xRange; i<xRange+3; i++) {
			for(int j=yRange; j<yRange+3; j++) {
				if(map[i][j]!=0) {
					check[map[i][j]]=true;
				}
			}
		}
		
		for(int i=1; i<10; i++) {
			if(!check[i]) {
				map[x][y]=i;
				go(level+1);
				map[x][y]=0;
			}
		}
	}
	
}