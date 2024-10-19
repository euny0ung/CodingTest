function solution(park, routes) {
    var answer = [];
    let startPos=[];
    
    const arr=park.map((pk)=> pk.split(''));
    
    const w=arr.length;
    const h=arr[0].length;
    
    for(let i=0; i<w; i++){
        for(let j=0; j<h; j++){
            if(arr[i][j]=='S'){
                startPos[0]=i;
                startPos[1]=j;
            }
        }
    }
    
    function isRange(x, y){
        return x>=0 && x<w && y>=0 && y<h;
    }
    
    function canGo(x,y){
        return arr[x][y]!=='X';
    }
    
    let nowX=startPos[0]; // 가로길이
    let nowY=startPos[1]; // 세로길이
    
    routes.map(route=>{
        const [op,n]=route.split(' ');
        const steps=parseInt(n);
        let flag=true;
        let lastX=nowX;
        let lastY=nowY;
        
        // 이동할 좌표
        if(op=='N'){
            lastX=nowX-steps;
        }else if(op=='S'){
            lastX=nowX+steps;
        }else if(op=='W'){
            lastY=nowY-steps;
        }else if(op=='E'){
            lastY=nowY+steps;
        }
        
        
        for(let i=1; i<=steps; i++){
            // 위 아래로 이동
            if(op=='N' || op=='S'){
                const nextX=op==='N' ? nowX-i : nowX+i;
                if(!isRange(nextX, nowY) || !canGo(nextX, nowY)){
                    flag=false;
                    break;
                }
           }else if(op=='W' || op=='E'){
            // 좌 우로 이동
               const nextY=op==='W' ? nowY-i : nowY+i;
               if(!isRange(nowX, nextY) || !canGo(nowX, nextY)){
                   flag=false;
                   break;
               }
           }
        }
       
        
        if(flag){
            nowX=lastX;
            nowY=lastY;
        }
        
    })
    
    answer.push(nowX);
    answer.push(nowY);
    
    
    return answer;
}