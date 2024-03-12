#include <bits/stdc++.h>

using namespace std;

int N; // 전기용품 사용횟수
int K; // 구멍의 개수

vector<int> A, V, visited(101,0);
int cnt ;

int main(){
    cin >> K >> N;
    A = vector<int>(N,0);
    for(int i = 0 ; i < N; ++i) cin >> A[i];
    for(int i = 0 ; i < N; ++i){
        
        if(!visited[A[i]]){

            if (V.size() == K){

                int last_idx =0, pos=101;
                for(int a: V){

                    int here_pick = 99999999;
                    for(int j = i+1; j < N ; ++j){
                        if ( a == A[j]){
                            here_pick = j; 
                            break;
                        }
                    }
                    if (last_idx < here_pick){
                        last_idx = here_pick;
                        pos = a;
                    }
                }

                visited[pos] = 0;
                cnt++;
                V.erase(find(V.begin(), V.end(), pos));
            }

            V.push_back(A[i]);
            visited[A[i]] = 1;

        }


    }
    cout << cnt ;
    

    return 0;
}