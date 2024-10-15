// 1. 비디오 길이, 오프닝, pos길이 초단위로 변환

class T{
    int min;
    int sec;
    public T(String s){
        String[] arr=s.split(":");
        min=Integer.parseInt(arr[0]);
        sec=Integer.parseInt(arr[1]);
    }
}

class Solution {
    public String solution(String video_len, String pos, String op_start, String op_end, String[] commands) {
        String answer = "";
        
        T cur=new T(pos);
        T start=new T(op_start);
        T end=new T(op_end);
        T max=new T(video_len);
        
        for(int i=0; i<commands.length; i++){
           
            if(commands[i].equals("prev")){ 
                int time=cur.min*60+cur.sec;
                if(time >= start.min*60+start.sec && time <=end.min*60+end.sec){
                    cur.min=end.min;
                    cur.sec=end.sec;
                }
                cur.sec-=10;
                if(cur.sec<0){
                    cur.min--;
                    cur.sec+=60;
                }
                // 범위 넘기면
                if(cur.min<0){
                    cur.min=0;
                    cur.sec=0;
                }
                // 남은 시간이 10초 미만이면
                if(cur.min==0 && cur.sec < 10){
                    cur.sec=0;
                }
                // 오프닝 구간이면
                time=cur.min*60+cur.sec;
                if(time >= start.min*60+start.sec && time <=end.min*60+end.sec)                 {
                    cur.min=end.min;
                    cur.sec=end.sec;
                }
            }else{ 
                int time=cur.min*60+cur.sec;
                // 오프닝 구간이면
                if(time >= start.min*60+start.sec && time <=end.min*60+end.sec)                 {
                    cur.min=end.min;
                    cur.sec=end.sec;
                }
                cur.sec+=10;
                if(cur.sec>=60){
                    cur.min++;
                    cur.sec-=60;
                }
                // 범위를 넘겼을 경우
                if(cur.min > max.min){
                    cur.min=max.min;
                    cur.sec=max.sec;
                }
                // 남은 시간이 10초 미만이면
                if(cur.min == max.min && max.sec-cur.sec < 10){
                    cur.sec=max.sec;
                }
                // 오프닝 구간이면
                time=cur.min*60+cur.sec;
                if(time >= start.min*60+start.sec && time <=end.min*60+end.sec){
                    cur.min=end.min;
                    cur.sec=end.sec;
                }
                // 남은 시간이 10초 미만이면
                if(max.min==cur.min && max.sec-cur.sec < 10){
                    cur.sec=max.sec;
                }
            }
            
        }
        
        String mins="";
        String seconds="";
        
        if(cur.min<10){
            mins="0"+cur.min;
        }else{
            mins=""+cur.min;
        }
        
        if(cur.sec<10){
            seconds="0"+cur.sec;
        }else{
            seconds=""+cur.sec;
        }
        
        answer=mins+":"+seconds;
        
        return answer;
    }
}