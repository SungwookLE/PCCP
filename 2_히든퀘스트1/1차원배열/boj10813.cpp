#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> basket;


int main(){
    cin >> N >> M;

    basket = vector<int>(N+1,0);
    for(int i = 1; i <= N ; ++i){
        basket[i] = i;
    }


    int i, j;
    for(int p = 0 ; p < M ; ++p){

        cin >> i >> j;

        int temp = basket[i];
        basket[i] = basket[j] ;
        basket[j] = temp;


    }

    for(int i = 1 ; i <= N ; ++i){
        cout << basket[i] << " ";
    }





    return 0;
}