#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> m;
int ans = 30*30;

void go(int row){

    if (row == N){
        // 디버깅을 위한 동전 전체 프린팅
        for(int i = 0 ; i < N ; ++i){
            for(int j = 0 ; j < N ;++j){
                if (m[i] & 1<<j) cout << 1 << " ";
                else cout << 0 << " ";
            }
            cout << endl;
        }
        cout << endl;
        int sum = 0;
        for(int j = 0; j < N ; ++j){
            int cnt = 0;
            for(int i = 0 ; i < N ; ++i)
                if (m[i] & 1<<j) cnt += 1;
            sum += min(cnt, N-cnt);
        }
        if (ans > sum) ans = sum;
        return;
    }
   
    go(row+1);
    m[row] = ~m[row];
    go(row+1);

    return;
}


int main(){
    cin >> N;

    for(int i = 0 ; i < N ; ++i){
        string s; cin >> s;
        int row = 0;
        for(int j = 0 ; j < N ; ++j){
          if (s[j] == 'T') row += 1<<j;
        } 
        m.push_back(row);
    }
    go(0);
    cout << ans;
    return 0;
}