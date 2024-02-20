#include <bits/stdc++.h>
using namespace std;
const int n = 4;
string a[4] = {"사과", "딸기", "포도", "배"};

void go(int num){
    string ret = "";
    for (int i = 0 ; i < 4 ; ++i){
        if (num & (1<<i)) ret += a[i] + " ";
    }
    cout << ret << "\n";
    return ;
}


int main(){
    for(int i = 1; i < n ; ++i){
        // 비트마스킹을 통해 visited 배열 없이도 주석의 효과를 낼 수 있음
        // visited[i] = 1; 
        go(1 | (1<<i));
        // visited[i] = 0; 
    }
    return 0;
} 