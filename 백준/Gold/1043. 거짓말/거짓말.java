import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

/*
 * 거짓말이 가능한 경우
- 이전 파티에서 진실을 들은 사람이 다음 파티에 포함되지 않은 경우
- 진실을 아는 사람이 파티에 없는 경우

=> boolean 배열을 만들어줘서 진실을 아는 사람은 true로 바꿔줌. (파티에 true인 사람이 껴있다면 그 파티에 참여한 사람은 모두 true로 바꿔줌)
=> 파티의 모든 사람이 false인 경우 cnt++
 * */
// 잘못 생각했음. 파티가 순서대로 열린다고 생각했는데 순서를 고려하지 않고 풀어야하는 문제...ㅠㅠ

public class Main {

	static int N,M;
	static int truthNum,truthPeople;
	static Queue<Integer>q;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine());
		N=Integer.parseInt(st.nextToken());
		M=Integer.parseInt(st.nextToken());
		q=new ArrayDeque<Integer>();
		
		int cnt=0;
		
		st=new StringTokenizer(br.readLine());
		truthNum=Integer.parseInt(st.nextToken());
		
		boolean[] trueParty=new boolean[M];
		
		// 진실을 알고 있는 사람
		for(int i=0; i<truthNum; i++) {
			truthPeople=Integer.parseInt(st.nextToken());
			q.add(truthPeople);
		}
		
		List<Integer>[] personList=new ArrayList[M];
		List<Integer>[] party=new ArrayList[51];
		
		for(int i=0; i<M; i++) {
			personList[i]=new ArrayList<>();
		}
		
		for(int i=0; i<51; i++) {
			party[i]=new ArrayList<>();
		}
		
		// 파티에 참가한 사람
		for(int i=0; i<M; i++) {
			
			int partyPeople=0, person=0;
			
			st=new StringTokenizer(br.readLine());
			partyPeople=Integer.parseInt(st.nextToken());
			
			for(int j=0; j<partyPeople; j++) {
				person=Integer.parseInt(st.nextToken());
				personList[i].add(person);
				party[person].add(i);
			}
		}
		
		while(!q.isEmpty()) {
			// 파티에 진실을 아는 사람이 껴있으면 해당 파티 true처리, 큐에 넣기
			int who=q.poll();
			
			// 진실을 아는 사람이 참여한 파티 true처리, 사람들 큐에 넣어주기
			for(int i=0; i<party[who].size(); i++) {
				int nowParty=party[who].get(i);
				if(!trueParty[nowParty]) {
					trueParty[nowParty]=true;
					for(int j=0; j<personList[nowParty].size(); j++) {
						q.add(personList[nowParty].get(j));
					}
				}
				
			}			
			
		}
		
		for(int i=0; i<M; i++) {
			if(!trueParty[i]) {
				cnt++;
			}
				
		}

		System.out.println(cnt);
	}



}