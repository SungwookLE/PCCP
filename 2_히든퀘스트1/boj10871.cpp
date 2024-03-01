#include <bits/stdc++.h>

using namespace std;

int N, X;
int A[10001];

int main(){
    cin >> N >> X;

    int a;
    int cnt = 0;
    for(int i = 0 ; i < N ; ++i){
        cin >> a;
        if ( a < X ){
            A[cnt] = a;
            cnt++;
        }
    }

    for(int i = 0 ; i < cnt ; ++i)
    cout << A[i] << " " ;




    return 0;
}