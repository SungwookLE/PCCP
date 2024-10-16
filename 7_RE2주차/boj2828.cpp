#include <bits/stdc++.h>
using namespace std;

int N; // 스크린 칸 크기
int M; // 바구니 칸 크기

int J; // 사과의 개수
vector<int> Apples;

int main(){

    cin >> N >> M >> J;
    Apples.resize(J);
    for(int i = 0 ; i < J ; ++i){
        cin >> Apples[i];
        Apples[i]--;
    }

    int CNT = 0;
    int S = 0;
    int E = S+M-1;

    for(auto loc: Apples){

        if (loc>=S && loc <=E){
            continue;
        }
        else{

            if (loc > E){
                CNT += (loc-E);
                E = loc;
                S = loc-(M-1);
            }
            else if (loc < S){
                CNT += (S-loc);
                S = loc;
                E = loc+(M-1); 
            }

        }
    }

    cout << CNT ;



    return 0;
}