import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static int N, W, L;
	static int[] truck;

	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine());
		
		Queue<Integer>q=new ArrayDeque<>();
		
		N=Integer.parseInt(st.nextToken());
		W=Integer.parseInt(st.nextToken());
		L=Integer.parseInt(st.nextToken());
		
		truck=new int[N];
		
		st=new StringTokenizer(br.readLine());
		
		for(int i=0; i<N; i++) {
			truck[i]=Integer.parseInt(st.nextToken());
		}
		
		int sum=0;
		int time=0;
		
		// n개의 트럭을 모두 이동 시키기
		
		for(int i=0; i<N; i++) {
			while(true) {
				
				//1. 큐가 꽉찼으면 하나빼기
				if(q.size()==W) {
					sum-=q.peek();
					q.poll();
				}
				
				//2. 큐 내부 트럭 + 넣으려는 트럭이 L보다 작으면 break. ( 트럭을 더 넣을 수 있음 )
				if(sum+truck[i]<=L) break;
					
				q.add(0);
				time++;
				
				
			}
			
			// 큐에 계속 트럭 넣기 ( sum, 시간 체크 )
				q.add(truck[i]);
				sum+=truck[i];
				time++;
		}
		
		time+=W; // 마지막 트럭을 빼는데 걸리는 시간
		System.out.println(time);
	}

}