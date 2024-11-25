#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer=0;
bool visited[17]={false,};

void dfs(int sheep, int wolf, const vector<int>& info, const vector<vector<int>>& edges){
        if(sheep<=wolf) return;
        answer=max(answer, sheep); // 이전에는 answer++ 했는데 이렇게 바꾸니 동작함
        
        for(int i=0; i<edges.size(); i++){
            // 부모 노드는 방문했고 자식 노드는 미방문이면 탐색
            if(visited[edges[i][0]] && !visited[edges[i][1]]){
                
                visited[edges[i][1]]=true;
                
                // 자식이 늑대인 경우
                if(info[edges[i][1]]==1){
                    dfs(sheep, wolf+1, info, edges);
                }
                // 자식이 양인 경우
                else{
                    dfs(sheep+1, wolf, info, edges);
                }
                
                visited[edges[i][1]]=false;
            }
        }
    }

int solution(vector<int> info, vector<vector<int>> edges) {
    
    visited[0]=true;
    
    dfs(1,0,info, edges);
    
    return answer;
}