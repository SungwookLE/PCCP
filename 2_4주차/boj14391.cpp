#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> p;
int ret = 0;

int main(){
    cin >> N >> M;
    p = vector<vector<int>>(N, vector<int>(M,0));

    for(int i = 0; i < N ; ++i){
        string s; cin >> s;
        for(int j =0 ; j < M ; ++j)
            p[i][j] = s[j]-'0';
    }

    for(int s = 0 ; s < (1<<(N*M)); ++s){

        int sum = 0;
        for(int i = 0 ; i < N ; ++i){
            int cur = 0;
            for(int j = 0 ; j < M ; ++j){

                int k = i * M +j;
                if ((s & (1<<k)) == 0){
                    cur = cur*10 + p[i][j];
                }
                else{
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        for (int j = 0; j < M; ++j){
            int cur = 0;
            for(int i = 0 ; i < N; ++i){
                int k = i*M+j;
                if((s & (1<<k))){
                    cur = cur*10 + p[i][j];
                }
                else{
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }

        ret = max(ret, sum);
    }

    cout << ret;

    return 0;
}