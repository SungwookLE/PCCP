#include <bits/stdc++.h>

using namespace std;

int N, M;

int a[101][101];
int main(){

    cin >> N >> M;


    for(int i = 0 ; i < N ; ++i){

        for(int j =0 ; j < M; ++j){
            cin >> a[i][j];
        }
    }
    int n;
    for(int i = 0 ; i < N ; ++i){

        for(int j =0 ; j < M; ++j){
            cin >> n;
            a[i][j] += n;
        }
    }

    for(int i =0 ; i < N; ++i){
        for(int j =0 ; j < M ; ++j){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }


    



    return 0;
}