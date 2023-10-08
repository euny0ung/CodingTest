import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;



/*1. 종유석, 석순을 따로 저장
2. 각각을 오름차순 정렬
3. 동굴의 높이만큼 계속 돌며 lowerbound를 하고 최솟값 갱신
- 최솟값보다 작으면 값을 갱신. cnt도 초기화
- 최솟값과 같으면 cnt++*/

public class Main {
	
	static List<Integer> seogsun; // 석순
	static List<Integer> jongyuseog; // 종유석
	
	
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine());
		
		int N = 0, H=0;
		int input=0;
		int min=Integer.MAX_VALUE;
		int cnt=0;
		
		N=Integer.parseInt(st.nextToken());
		H=Integer.parseInt(st.nextToken());
		
		seogsun=new ArrayList<>();
		jongyuseog=new ArrayList<>();
		
		
		// 종유석과 석순을 따로 저장
		for(int i=0; i<N; i++) {
			st=new StringTokenizer(br.readLine());
			input=Integer.parseInt(st.nextToken());
			if(i%2==0) seogsun.add(input);
			else jongyuseog.add(input);
		}
		
		// 오름차순 정렬
		Collections.sort(seogsun);
		Collections.sort(jongyuseog);
		
		// 이진탐색을 통해 lowerbound 구하기 (동굴의 높이 범위가 커서 이진탐색을 하는게 좋음)
		for(int i=1; i<H+1; i++) {
			 int totalConflict=lowerbound(seogsun, i)+lowerbound(jongyuseog, H-i+1);
			if(min>totalConflict) {
				min=totalConflict;
				cnt=1;
			}
			else if(min==totalConflict) cnt++;
			
		}
		
		 System.out.println(min+" "+cnt);
	}

	private static int lowerbound(List<Integer> list, int searchBar) {
		// searchBar보다 큰 수가 나오는 첫번째 인덱스 구하기
		int conflict=binarySearch(list, searchBar);
		
		/* System.out.println("구간: "+searchBar+" "+"lowerbound: "+conflict); */
		return conflict;
	}

	private static int binarySearch(List<Integer> list, int searchBar) {
		int start=0;
		int end=list.size();

		while(start<end) {
			int middle=(start+end)/2;
			
			if(list.get(middle)>=searchBar) {
				end=middle;
			}
			else {
				start=middle+1;
			}
		}
		
		int idx=list.size()-end;
		return idx;
	}
}