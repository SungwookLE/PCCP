#include <bits/stdc++.h>

using namespace std;
int N;

int main(){

    cin >> N;


    vector<int>V(N+1,0);
    V[1] = 3;
    for(int i = 2; i <= N ; ++i){
        V[i] = V[i-1]*2-1;
    }

    cout << V[N]*V[N] ;





    return 0;
}