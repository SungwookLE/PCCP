#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    
    int mn = 50000;
    if (s.size() == 1){
        return 1;
    }
    
    for(int len = 1; len <= s.size()/2; ++len){

        
        string ret = "";
        string prevToken = s.substr(0, len);
        int cnt = 1;
        for(int i = len; i <= s.size()-len; i+=len){
            string token = s.substr(i, len);
            if(token == prevToken){
                cnt++;
            }
            else{
                if (cnt > 1) ret += to_string(cnt) + prevToken;
                else ret += prevToken;
                cnt = 1;
            }
            prevToken = token;
        }
        if (cnt>1) ret += to_string(cnt)+prevToken;
        else ret += prevToken;
        
        ret += s.substr(s.size() - s.size()%len);
        //cout << ret << endl;
        if (mn > ret.size()) mn = ret.size();
        
        
        
    }
    
    answer = mn;
    
    
    return answer;
}