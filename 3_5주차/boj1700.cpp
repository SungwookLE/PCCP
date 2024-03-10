#include <bits/stdc++.h>

using namespace std;

int N; // 구멍의 개수
int K; // 전기용품 사용횟수

vector<int> E;
int main(){
    cin >> N >> K;

    E = vector<int>(K,0);
    for(int i =0 ; i < K ; ++i) cin >> E[i];

    vector<int> IN(N,0);
    for(int i = 0 ; i < N ; ++i){
        IN[i] = E[i];
    }


    vector<int> T;
    int ret = 0;
    for(int i = N; i < K; ++i){

        bool isIn = false;
        for(auto I : IN){
            if (E[i] == I){
                isIn = true;
                break;
            }
        }

        if (!isIn) T.push_back(E[i]);


        if (T.size() == N){
            IN = T;
            T.clear();
            ret+=N;
        }

    }

    ret+= T.size();
    cout << ret;




    return 0;
}