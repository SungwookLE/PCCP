#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

string go(string& p){
    
    if (p.empty()){
        return "";
    }
    
    string ret = "";
    
    int open = 0, close = 0;
    string u, v;
    for(int i =0 ;i < p.size(); ++i){
        if (p[i] == '('){
            open++;
            u.push_back('(');
        } 
        else{
            close++;
            u.push_back(')');
        } 
        
        if (open == close){
            v = p.substr(i+1);
            break;
        }
    }
    
    stack<char> u_stk;
    for(int i = 0; i < u.size(); ++i){
        char temp = u[i];
        if (u_stk.empty()) u_stk.push(temp);
        else{
            if (u_stk.top() == '(' && temp == ')') u_stk.pop();
            else u_stk.push(temp);
        }
    }
    
    if(u_stk.empty()){
        // 올바른 문자열임
        ret += u;
        p = v;
        ret+=go(p);
    }
    else{
        ret += '(';
        p = v;
        ret += go(p);
        ret += ')';
        u = u.substr(1);
        u.pop_back();
        
        for(int i =0 ;i < u.size(); ++i){
            if (u[i] == '(') u[i] = ')';
            else u[i] = '(';
        }
        
        ret += u;
    }
    
    
    return ret;
}

string solution(string p) {
    string answer = "";
    
    answer = go(p);
    
    
    return answer;
}