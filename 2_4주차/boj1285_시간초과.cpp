#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> m;
map<string, int> visited;
int ans = 30*30;

void go(int cnt){

    int sum = 0;
    for(auto mmm : m){
        for(int mm : mmm) if (mm==1) sum +=1;
    }
    if (ans > sum) ans = sum;

    string id = "";
    cnt++;
    for(int i =0 ; i < N ; ++i){
        for(int j =0 ; j < N ; ++j){
          m[i][j] ^= 1;
        } 

        id = to_string(i*100);

        if (visited[id] == 0){
            visited[id] = 1;
      
            go(cnt+1);

            for(int j =0 ; j < N ; ++j) m[i][j] ^= 1;
            visited[id] = 0;
        }
    }
    for(int j = 0 ; j < N ;++j){
        for(int i = 0 ; i < N ; ++i){
            m[i][j] ^= 1;
        }

        id = to_string(j);

        if (visited[id] == 0){
            visited[id] = 1;
      
            go(cnt+1);

            for(int i =0 ; i < N ; ++i) m[i][j] ^= 1;
            visited[id] = 0;
        }
    }

   
}


int main(){
    cin >> N;
    m = vector<vector<int>>(N, vector<int>(N));

    string id;
    for(int i = 0 ; i < N ; ++i){
        string s; cin >> s;
        for(int j = 0 ; j < N ; ++j){
            if (s[j] == 'H'){
                m[i][j] = 0;
            }
            else{ // 뒷면
                m[i][j] = 1;
            } 
        } 
    }

    visited[id] = 1;
    go(0);

    cout << ans << "\n";

    return 0;
}