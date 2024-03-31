#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
#define INIT 205
int ans = INIT;

bool allvisit(const vector<int>& w){
    for(int i =0 ; i< w.size() ; ++i){
        if (w[i] != -1) return false;
    }
    return true;
}

void go(int idx, int cur, int cnt , const int n, const vector<int>& d, vector<int>& w){
    
    vector<int> prevW = w;
    
    if (allvisit(w)){
        // cout << "====> MAN:" << cnt << endl;
        if (ans > cnt) ans = cnt;
        return;
    }
    
    if (idx == d.size()){
        // cout << "NO\n";
        return;
    }
    
    int next;
    for(int i = idx ; i < d.size(); ++i){
        bool is_next = false;
        
        // 1. 시계방향 이동
        next = (n+cur+d[i])%n;
        
            // 방문처리
            if (cur<=next){
                for(int& j : w)
                    if (j>= cur && j <= next) j = -1;
            }
            else{
                for(int& j : w){
                    if (j>= cur && j<n) j = -1;
                    else if (j>=0 && j<=next) j = -1;
                }
            }
        
            // 다음 외벽을 start 지점으로 설정
            for(int w_next: w){
                if (w_next > next && w_next != -1){
                    next=w_next;
                    is_next = true;
                }
            }
            if(!is_next){
                for(int w_next : w){
                    if(w_next != -1){
                        next = w_next;
                        is_next = true;
                        break;
                    }
                }
            }
            
            // propagation
            go(i+1, next, cnt+1, n, d, w);
        
            // 원복
            w = prevW;

        // 2. 반시계방향 이동
        next = (n+cur-d[i])%n;

            // 방문 처리
            if (cur>=next){
                for(int&j : w)
                    if (j>=next && j<=cur)
                        j = -1;
            }
            else{
                for(int&j : w){
                    if (j>=0 && j<=cur) j = -1;
                    else if (j>=next && j< n) j= -1;
                }
            }
            
 
                  
            // 다음 외벽을 start 지점으로 설정
            is_next = false;
            for(auto w_next = w.rbegin(); w_next != w.rend(); ++w_next){
                if ( *w_next < next && *w_next != -1){
                    next = *w_next;
                    is_next = true;
                    break;
                }
            }
        
            if(!is_next){
                for(auto w_next = w.rbegin(); w_next != w.rend(); ++w_next){
                if(*w_next != -1){
                    next=*w_next;
                    is_next = true;
                    break;
                }
                }
            }
        
            // propagation
            go(i+1, next, cnt+1, n, d, w);

            // 원복
            w = prevW;
    }
    
    return;
}


int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 0;
    
    sort(dist.begin(), dist.end());
    for(int i =0 ; i < weak.size(); ++i){
        // void go(int idx, int cur, int cnt , const int n, const vector<int> d, const vector<int> w)
        go(0, weak[i], 0, n, dist, weak);
    }
    
    reverse(dist.begin(), dist.end());
    for(int i =0 ; i < weak.size(); ++i){
        // void go(int idx, int cur, int cnt , const int n, const vector<int> d, const vector<int> w)
        go(0, weak[i], 0, n, dist, weak);
    }
   
    if (ans == INIT) answer = -1;
    else answer = ans;
    
    return answer;
}


