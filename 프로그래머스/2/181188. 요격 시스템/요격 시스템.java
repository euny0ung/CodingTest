import java.util.*;

class Solution {
    public int solution(int[][] targets) {
        int answer = 0;
        
        Arrays.sort(targets, (o1, o2)->o1[1]-o2[1]);
        
        int before=0;
        
        for(int i=0; i<targets.length; i++){
            if(before <= targets[i][0]){ 
                // 시작이 이전 끝값보다 작다면 한번에 요격 가능. 그렇지 않으면 새로 발사하고 기준 바꿔야함
                before=targets[i][1]; // 끝
                answer++;
            }
        }
        
        return answer;
    }
}