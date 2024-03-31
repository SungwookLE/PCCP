#include <bits/stdc++.h>

using namespace std;

int N;
int main(){


    cin >> N;


    int S = 1;
    int V = 0;
    for(int i = 1 ; i <= N; ++i){

        if (N <= S){
            cout << i ;
            break;
        }
        V += 6;
        S += V;


    }

    



    return 0;
}