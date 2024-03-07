#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> A;
vector<int> B;
queue<int> Q;
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
    for(int i = N-1 ; i >= 0 ; --i)
        if (A[i] == 0) Q.push(B[i]);

    cin >> M;
    int q_id = 0;
    for(int i = 0 ; i < M ; ++i){
        cin >> c;
        Q.push(c);
        cout << Q.front() << " ";
        Q.pop();
    }   


    return 0;
}