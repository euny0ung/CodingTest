import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		int input=0, result=0;
		
		for(int i=0; i<5; i++) {
			input=Integer.parseInt(br.readLine());
			
			if(input<40) result+=40;
			else result+=input;
		}
		
		System.out.println(result/5);
	}

}