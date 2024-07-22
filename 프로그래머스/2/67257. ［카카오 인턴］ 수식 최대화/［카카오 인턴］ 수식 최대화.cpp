#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

map<char,int>mp; // 연산자, 우선순위 저장
long long maxValue = 0;

long long eval(long a, long b, char op){
       if(op=='+') return a + b;
        else if(op=='-') return a-b;
        else return a*b;
}

// 순열 생성
void dfs(int depth, vector<char>& op, string exp){
    if(depth<op.size()){
        for(int i=0; i<op.size(); i++){
            // 이 if문 추가했더니 모든 테케 맞았음..
            if(mp.find(op[i])==mp.end()){
                  // 할당값 i에서 depth로 변경
                mp[op[i]]=depth;
                dfs(depth+1, op, exp);
                // 조언에 따라 추가
                mp.erase(op[i]);
            }
          
        }
    }
    else{
        stack<char> st;
        vector<string> print;
        stack<long long> answer;
        
        string num="";
        
        // 후위 표기법으로 변환
        for(char c: exp){
            if(isdigit(c)){
                num+=c;
            }
            else{
                if(!num.empty()){
                    print.push_back(num); 
                    num="";
                }
              
                // 스택 연산자와 현재 연산자 우선순위 비교
                while(!st.empty() && mp[st.top()]>=mp[c]){
                        print.push_back(string(1, st.top()));
                        st.pop();
                } 
                st.push(c);
            }
        }
        if(!num.empty()) {
            print.push_back(num);
            num="";
        }
        
        while(!st.empty()){
            // 정답이랑 너무 거리가 멀어서 to_string대신 string()썼더니 테케 하나 통과
            print.push_back(string(1, st.top())); 
            st.pop();
        }
        
        // 후위 표기법에 따라 연산 (이 for문 부분때문에 계속 테케1 틀린거였음.. a b 순서 거꾸로 써서...)
        for(int i=0; i<print.size(); i++){
            if(print[i]=="+" || print[i]=="-" || print[i]=="*"){
                long long b= answer.top();
                answer.pop();
                long long a=answer.top();
                answer.pop();
                
                long long result = eval(a ,b , print[i][0]);
                answer.push(result);
            }
            else{
                answer.push(stoll(print[i]));
            }
        }
        
        maxValue=max(maxValue, abs(answer.top()));
       
        return;
    }
}

long long solution(string expression) {
    vector<char> operators;
    
    for(char c: expression){
        if(!isdigit(c)){
            if(find(operators.begin(), operators.end(), c)==operators.end()){
                operators.push_back(c);
            }
        }
    }
    
    dfs(0, operators, expression);
    
    return maxValue;
}

