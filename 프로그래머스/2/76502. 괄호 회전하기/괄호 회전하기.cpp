#include <string>
#include <vector>
#include <stack>
#include <map>

using namespace std;

int solution(string s) {
    int answer = 0;
    int len=s.length();
    map<char, int>mp={
        {'[',1},
        {']',1},
        {'{', 2},
        {'}',2},
        {'(',3},
        {')',3},
    };
    
    for(int i=0; i<len; i++){
        stack<char>st;
        bool flag=0;
        for(int j=0; j<len; j++){
            char ch=s[(i+j)%len];
            if(ch=='[' || ch=='(' || ch=='{') st.push(ch);
            else{
                if(st.empty()){
                    flag=1;
                    break;
                } 
                if(mp[st.top()]==mp[ch]) st.pop();
                else{
                    flag=1;
                    break;
                }
            }
        }
        if(st.empty() && flag==0) answer++;
    }
    
    
    return answer;
}