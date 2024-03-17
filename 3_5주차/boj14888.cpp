#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A;
vector<int> OP(4,0);

int mn =  2000000000;
int mx = -2000000000;

void go(int depth, int ret){

    if (depth == N){
        if (mn > ret) mn = ret;
        if (mx < ret) mx = ret;
        return;
    }

    for(int i =0 ; i < 4 ;++i){

        if (OP[i]>0){
            OP[i] -= 1;
            switch (i)
            {
            case 0:
                ret += A[depth];
                go(depth+1, ret);
                ret -= A[depth];
                break;
            case 1:
                ret -= A[depth];
                go(depth+1, ret);
                ret += A[depth];
                break;
            case 2:
                ret *= A[depth];
                go(depth+1, ret);
                ret /= A[depth];

                break;
            case 3:
                ret /= A[depth];
                go(depth+1, ret);
                ret *= A[depth];
                break;
            }

            OP[i] += 1;
        }

    }

}


int main(){
    cin >> N;

    A = vector<int>(N,0);
    for(int i = 0 ; i < N ; ++i) cin >> A[i];
    for(int i = 0 ; i < 4 ; ++i) cin >> OP[i];


    go(1, A[0]);

    cout <<mx << endl;
    cout <<mn << endl;



    return 0;
}