#include <bits/stdc++.h>

using namespace std;

int N, M;
map<int, int> A;


int main(){
    cin >> N >> M;

    int a;
    for(int i =0 ; i < N ; ++i){
        cin >> a;
        A[a] = 1;
    }      
    int b;   
    for(int i =0 ; i < M ; ++i){
        cin >> b;
        A[b] -= 1;
    } 
    int ret = 0;
    for(auto it = A.begin(); it != A.end(); ++it){
        if (it->second == 1 || it->second ==-1) ret++;
    }

    cout << ret << endl;


    return 0;
}