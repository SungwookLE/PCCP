#include <bits/stdc++.h>

using namespace std;

int p, q;
int main(){
    cin >> p >> q;

    int cnt = 0;
    for(int i = 1; i <= p ; ++i){

        if (p%i == 0){
            cnt++;
            if (cnt == q){
                cout << i ;
                break;
            }
        }


    }

    if (cnt < q) cout << 0;


    return 0;
}