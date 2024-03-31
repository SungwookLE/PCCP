#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> basket;
int main(){
    cin >> N >> M;

    basket = vector<int>(N+1,0);

    int i, j ,k;
    for(int p = 0 ; p < M ; ++p){

        cin >> i >> j >> k;

        for(int q = i ; q <= j ; ++q){
            basket[q] = k;
        }
    }

    for(int r = 1; r <= N ; ++r){
        cout << basket[r] << " "; 
    }


    return 0;
}