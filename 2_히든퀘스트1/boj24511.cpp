#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> A;
vector<int> B;
int c, ret;

int main(){

    cin.tie(NULL);
    cout.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    cin >> N;
    A = vector<int>(N,0);
    B = vector<int>(N,0);

    for(int i =0 ; i < N; ++i) cin >> A[i];
    for(int i =0 ; i < N; ++i) cin >> B[i];

    for(int i = N-1 ; i >= 0 ; --i){
        if (A[i] == 1){
            A.erase(A.begin()+i);
            B.erase(B.begin()+i);
        }
    }

    cin >> M;
    for(int i =0 ; i < M; ++i){
        cin >> c; ret = c;
        for(int j = 0 ; j < A.size() ; ++j){
            int temp = ret;
            ret = B[j];
            B[j] = temp;
        }

        cout << ret << " ";
    } 

    return 0;
}