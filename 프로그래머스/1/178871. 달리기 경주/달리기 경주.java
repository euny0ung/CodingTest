import java.util.*;

class Solution {
    public String[] solution(String[] players, String[] callings) {
        String[] answer = new String[players.length];
        
        HashMap<String, Integer> mappedByPlayer=new HashMap<>();
        HashMap<Integer,String> mappedByRank=new HashMap<>();
        
        for(int i=0; i<players.length; i++){
            mappedByPlayer.put(players[i],i);
            mappedByRank.put(i, players[i]);
        }
        
        for(int i=0; i<callings.length; i++){
            // 추월한 유저 순위, 유저 이름
            int rank=mappedByPlayer.get(callings[i]);
            String player=mappedByRank.get(rank);
            
            // 바로 앞 플레이어
            String frontPlayer=mappedByRank.get(rank-1);
            
            // swap
            mappedByPlayer.put(player, rank-1);
            mappedByPlayer.put(frontPlayer, rank);
            
            mappedByRank.put(rank-1, player);
            mappedByRank.put(rank, frontPlayer);
        }
        
        for(int i=0; i<players.length; i++){
            answer[i]=mappedByRank.get(i);
        }
        
        return answer;
    }
}