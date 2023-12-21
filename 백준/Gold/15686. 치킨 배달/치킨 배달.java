import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int N, M;
	static int[][] arr;
	static ArrayList<int[]> chicken;
	static ArrayList<int[]> house;
	static ArrayList<int[]> picked;
	static int ans;
	static int prevAns;

	static int count;

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		arr = new int[N][N];
		chicken = new ArrayList<>();
		house = new ArrayList<>();
		picked = new ArrayList<>();

		prevAns = Integer.MAX_VALUE;

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				int input = Integer.parseInt(st.nextToken());
				arr[i][j] = input;

				// 치킨집, 집은 따로 분류
				if (input == 2)
					chicken.add(new int[] { i, j });
				else if (input == 1)
					house.add(new int[] { i, j });
			}
		}

		// list로 M개 조합 구하기
		comb(0, 0);

		System.out.println(prevAns);

	}

	public static void comb(int cnt, int start) {
		if (cnt == M) {

			count++;
			ans = 0;

			// 각 집에서 치킨집까지의 최소 거리 구하기
			for (int i = 0; i < house.size(); i++) {

				int houseX = house.get(i)[0];
				int houseY = house.get(i)[1];

				int min = Integer.MAX_VALUE;

				for (int j = 0; j < picked.size(); j++) {
					int result = Math.abs(houseX - picked.get(j)[0]) + Math.abs(houseY - picked.get(j)[1]);
					if (min > result)
						min = result;
				}

				ans += min;

//				System.out.println(count + "번째 시도에서 값 : " + ans);

			}


			/*
			 * for(int i=0; i<picked.size(); i++) {
			 * System.out.println(picked.get(i)[0]+" "+picked.get(i)[1]); }
			 */


			// 총 합 중에서도 최소값 구하기
			prevAns = Math.min(ans, prevAns);

		}

		// 치킨집 중에서 M개 구하기
		for (int i = start; i < chicken.size(); i++) {
			picked.add(chicken.get(i));
			comb(cnt + 1, i + 1);
			picked.remove(chicken.get(i));
		}

	}

}