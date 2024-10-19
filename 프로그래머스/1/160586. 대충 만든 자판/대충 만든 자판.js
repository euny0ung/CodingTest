function solution(keymap, targets) {
    var answer = [];
    let keyMinValue=new Map();
    
    keymap.forEach((key)=>{
        for(let ch of key){
            const pressCnt=key.indexOf(ch)+1;
            
            // 키가 없거나 pressCnt가 기존 값보다 작으면 갱신
            if(!keyMinValue.has(ch) || keyMinValue.get(ch)>pressCnt){
                keyMinValue.set(ch, pressCnt);
            }
        }
    })
    
    // 입력 최소 키 계산
    targets.forEach(target=>{
        
        let total=0;
        
        for(let ch of target){
            if(keyMinValue.has(ch)){
                total+=keyMinValue.get(ch);
            }
            else{
                total=-1;
                break;
            }
        }
        
        answer.push(total);
    })
    
    return answer;
}