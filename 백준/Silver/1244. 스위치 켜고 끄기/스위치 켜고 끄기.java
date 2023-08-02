import java.util.Arrays;
import java.util.Scanner;

/*
 * 1. 스위치 개수만큼 배열로 상태 입력
 * 2. 학생 수 만큼 for문
 * 3. for문 내부: if문으로 성별에 따라 다른 함수 호출(매개변수는 스위치)
 * 4. 남자함수 : for문으로 만약 i가 s의 배수면 상태 변경
 * 5. 여자함수 : for문(i=1~스위치개수/2)으로 arr[s-i]와 arr[s+i] 비교. 같으면 상태 변경 다르면 break. 이때 arr[s]는 무조건 상태 변경 
 * !! 스위치 번호는 1부터 시작이지만 배열은 0부터 시작이라는것 주의!!
 * */

public class Main {
	static int sSize, studentSize, who, sNum;
	static int []arr;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		sSize=sc.nextInt();
		arr=new int[sSize+1];
		
		for(int i=1; i<=sSize; i++) {
			arr[i]=sc.nextInt();
		}
		
		studentSize=sc.nextInt();
		
		for(int i=0; i<studentSize; i++) {
			who=sc.nextInt();
			sNum=sc.nextInt();
//			System.out.println(who + " | " + sNum);
			if(who==1) {
				// 남자 함수 호출
				Boy(sNum);
			}
			if(who==2) {
				// 여자함수 호출
				Girl(sNum);
			}
		}
		
		for(int i=1; i<=sSize; i++) {
			System.out.print(arr[i]+" ");
			if(i % 20 == 0) {
				System.out.println();
			}
			
		}
	}
	
	static void Boy(int sNum) {
		for(int i=1; i<=sSize; i++) {
			if(i%sNum==0) {
				if(arr[i]==1) arr[i]--;
				else arr[i]++;
			}
		}
	}
	
	static void Girl(int sNum) {
		if(arr[sNum]==1) arr[sNum]--;
		else arr[sNum]++;
		
		// 구간 조심
		
		for(int i=1; i<=sNum; i++) {
			
			if ((0 < sNum && sNum < arr.length - 1) && 
					((0 < (sNum-i)) && ((sNum+i) <= arr.length - 1))) {
				
				if(arr[sNum-i] == arr[sNum+i]) {
					
					// 상태변경
					if(arr[sNum-i]==1) arr[sNum-i]--;
					else arr[sNum-i]++;
					if(arr[sNum+i]==1) arr[sNum+i]--;
					else arr[sNum+i]++;
				}
				else {
					break;
				}
			} else return;
		}
	}

}

//if ((0 < sNum && sNum < arr.length - 1) &&
//		(0 < sNum-i && sNum-i < arr.length - 1) &&
//		(0 < sNum+i && sNum+i < arr.length - 1)) {