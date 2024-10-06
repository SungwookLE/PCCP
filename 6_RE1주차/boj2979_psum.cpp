#include <bits/stdc++.h>
using namespace std;

int A, B, C;

int cstar[101] = {0,};
int pstar[101] = {0,};

int main(){

    cin >> A >> B >> C;

    int a , b;
    for(int i =0 ; i < 3; ++i){
        cin >> a >> b;
        cstar[a]++;
        cstar[b]--;
    }
    
    int ans = 0;
    for(int i =1 ; i < 101; ++i){
        pstar[i] = pstar[i-1] + cstar[i];

        if (pstar[i] == 1){
            ans += A;
        }
        else if (pstar[i] == 2){
            ans += 2*B;
        }
        else if (pstar[i] == 3){
            ans += 3*C;
        }

    }

    cout << ans;




    return 0;
}